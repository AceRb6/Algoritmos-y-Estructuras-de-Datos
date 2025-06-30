#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_USERS 7
#define MAX_ITEMS 6
#define KEY_FILES_FOR_QUEUE "../request_response.h"
#define KEY_FILES_FOR_SHM_SHOP "./db/shop"
#define KEY_FILES_FOR_SHM_CART "./db/carts"
#define SHM_SHOP_KEY 'S'
#define SHM_CART_KEY 'C'
#define RESPONSE_KEY 'K'
#define REQUEST_KEY 'L'
#define GET_PRODUCTS 'a'
#define ADD_PRODUCT_TO_CART 'b'
#define SHOW_CART_CONTENT 'c'
#define MODIFY_STOCK_FROM_CART 'd'
#define DELETE_PRODUCT_FROM_CART 'l'
#define BUY_PRODUCTS 'f'

typedef struct {
    unsigned int user_id;
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    float money_to_buy;
} User;

typedef struct {
    int shmid;
    unsigned short int item_id;
    char name[MAX_LENGTH];
    float price;
    unsigned int stock;
} Item;

typedef struct {
    int shmid;
    unsigned int user_id;
    Item _items[MAX_ITEMS];
} SharedMemoryCart;

typedef struct {
    int shmid;
    Item _items[MAX_ITEMS];
} SharedMemoryShop;

typedef struct {
    long pid;
    char request_type;
    unsigned int user_id;
    unsigned short int response_status_code;
} RequestAndResponse;

void init_queues(int *res_queue, int *req_queue);
SharedMemoryShop *init_shop_shared_memory();
SharedMemoryCart *init_cart_shared_memory();
void get_users(User *_user);
void get_products(Item *_item);
void show_products(Item *_items, unsigned short int status_code);
void show_options();
void send_request(int _request_queue, int _response_queue, SharedMemoryShop *shop_items);
User *init_users_structures();

int main(int argc, char const *argv[]) {
    int request_queue;
    int response_queue;
    SharedMemoryShop *shop_items;
    SharedMemoryCart *cart_items;

    init_queues(&request_queue, &response_queue);
    shop_items = init_shop_shared_memory();
    cart_items = init_cart_shared_memory();

    while (1) {
        send_request(request_queue, response_queue, shop_items);
    }

    return 0;
}


void init_queues(int *res_queue, int *req_queue) {
    key_t _key;

    _key = ftok(KEY_FILES_FOR_QUEUE, RESPONSE_KEY);
    *res_queue = msgget(_key, IPC_CREAT | 0666);
    if (*res_queue == -1) {
        perror("No se pudo crear la cola de mensajes servidor - cliente");
        exit(EXIT_FAILURE);
    }

    _key = ftok(KEY_FILES_FOR_QUEUE, REQUEST_KEY);
    *req_queue = msgget(_key, IPC_CREAT | 0666);
    if (*req_queue == -1) {
        perror("No se pudo crear la cola de mensajes cliente - servidor");
        exit(EXIT_FAILURE);
    }
}

SharedMemoryShop *init_shop_shared_memory() {
    key_t _key;
    int shmid;
    SharedMemoryShop *item_list;

    _key = ftok(KEY_FILES_FOR_SHM_SHOP, SHM_SHOP_KEY);
    shmid = shmget(_key, sizeof(SharedMemoryShop), IPC_CREAT | 0600);
    if (shmid == -1) {
        perror("No se pudo crear la memoria compartida de la tienda");
        exit(EXIT_FAILURE);
    }

    item_list = (SharedMemoryShop *)shmat(shmid, NULL, 0);
    if (item_list == (void *)-1) {
        perror("No se pudo adjuntar la memoria compartida de la tienda");
        exit(EXIT_FAILURE);
    }

    return item_list;
}

SharedMemoryCart *init_cart_shared_memory() {
    key_t _key;
    int shmid;
    SharedMemoryCart *cart;

    _key = ftok(KEY_FILES_FOR_SHM_CART, SHM_CART_KEY);
    shmid = shmget(_key, sizeof(SharedMemoryCart), IPC_CREAT | 0600);
    if (shmid == -1) {
        perror("No se pudo crear la memoria compartida del carrito");
        exit(EXIT_FAILURE);
    }

    cart = (SharedMemoryCart *)shmat(shmid, NULL, 0);
    if (cart == (void *)-1) {
        perror("No se pudo adjuntar la memoria compartida del carrito");
        exit(EXIT_FAILURE);
    }

    return cart;
}

void get_users(User *_user) {
    FILE *_file = fopen("./db/users", "r+");
    int user_num = 0;
    if (_file == NULL) {
        fprintf(stderr, "No se pudo conectar a la base de datos\n\e[4;31m\e[1m Error :\e[0m \n");
    }
    while (fscanf(_file, "%u %s %s %f", &_user[user_num].user_id, _user[user_num].username, _user[user_num].password, &_user[user_num].money_to_buy) != EOF) {
        user_num++;
    }
    fclose(_file);
}

void get_products(Item *_item) {
    FILE *_file = fopen("./db/shop", "r+");
    int item_num = 0;
    if (_file == NULL) {
        fprintf(stderr, "No se pudo conectar a la base de datos\n\e[4;31m\e[1m Error :\e[0m \n");
    }
    while (fscanf(_file, "%hu %s %f %u", &_item[item_num].item_id, _item[item_num].name, &_item[item_num].price, &_item[item_num].stock) != EOF) {
        item_num++;
    }
    fclose(_file);
}

void show_products(Item *_items, unsigned short int status_code) {
    int i;

    if (status_code == 1) {
        printf("Productos disponibles:\n");
        for (i = 0; i < MAX_ITEMS; i++) {
            printf("ID: %d, Nombre: %s, Precio: %.2f, Stock: %d\n",
                   _items[i].item_id, _items[i].name, _items[i].price, _items[i].stock);
        }
    } else {
        printf("No se pudo obtener la lista de productos.\n");
    }
}

void show_options() {
    printf("Opciones:\n");
    printf("a - Obtener lista de productos\n");
    printf("b - Agregar producto al carrito\n");
    printf("c - Mostrar contenido del carrito\n");
    printf("d - Modificar stock desde el carrito\n");
    printf("l - Eliminar producto del carrito\n");
    printf("f - Comprar productos\n");
    printf("q - Salir\n");
}

void send_request(int _request_queue, int _response_queue, SharedMemoryShop *shop_items) {
    char option;
    RequestAndResponse message;
    _Bool is_wait_response = 0;
    long unsigned int _pid = getpid();
    message.pid = _pid;
    show_options();
    scanf("\n%c", &option);
    switch (option) {
        case 'a':
            is_wait_response = 1;
            message.request_type = GET_PRODUCTS;
            msgsnd(_request_queue, &message, sizeof(RequestAndResponse) - sizeof(long), 0);
            break;
        case 'b':
            is_wait_response = 1;
            message.request_type = ADD_PRODUCT_TO_CART;
            msgsnd(_request_queue, &message, sizeof(RequestAndResponse) - sizeof(long), 0);
            break;
        case 'c':
            is_wait_response = 1;
            message.request_type = SHOW_CART_CONTENT;
            msgsnd(_request_queue, &message, sizeof(RequestAndResponse) - sizeof(long), 0);
            break;
        case 'd':
            is_wait_response = 1;
            message.request_type = MODIFY_STOCK_FROM_CART;
            msgsnd(_request_queue, &message, sizeof(RequestAndResponse) - sizeof(long), 0);
            break;
        case 'l':
            is_wait_response = 1;
            message.request_type = DELETE_PRODUCT_FROM_CART;
            msgsnd(_request_queue, &message, sizeof(RequestAndResponse) - sizeof(long), 0);
            break;
        case 'f':
            is_wait_response = 1;
            message.request_type = BUY_PRODUCTS;
            msgsnd(_request_queue, &message, sizeof(RequestAndResponse) - sizeof(long), 0);
            break;
        case 'q':
            printf("Hasta luego \n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Ingresar una entrada válida \n");
            break;
    }

    if (is_wait_response) {
        is_wait_response = 0;
        msgrcv(_response_queue, &message, sizeof(RequestAndResponse) - sizeof(long), _pid, 0);
        switch (message.request_type) {
            case GET_PRODUCTS:
                show_products(shop_items, message.response_status_code);
                break;
            case ADD_PRODUCT_TO_CART:
                /*Tratamiento de operación*/
                break;
            case SHOW_CART_CONTENT:
                /*Tratamiento de operación*/
                break;
            case MODIFY_STOCK_FROM_CART:
                /*Tratamiento de operación*/
                break;
            case DELETE_PRODUCT_FROM_CART:
                /*Tratamiento de operación*/
                break;
            case BUY_PRODUCTS:
                /*Tratamiento de operación*/
                break;
            default:
                printf("Algo ha salido mal \n");
                exit(EXIT_FAILURE);
                break;
        }
    }
}

