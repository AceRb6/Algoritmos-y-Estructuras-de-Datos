#include "client.h"
void show_products(struct shared_memory_shop *, unsigned short int);
void show_options(){
	printf("\e[95m\e[1m Bienvenido a la tiendita de paises \e[0m \n");
	printf( "1.- Ver productos \n" "2.- Agregar productos \n" "3.- Editar carrito \n" "4.- Mostrar contenido del carrito \n" "5.- Modificar cantidad de un producto del carrito \n" "6.- Comprar productos \n" "7.- Salir \n");
}

void send_request( int _request_queue, int _response_queue,struct shared_memory_shop *shop_items ){
	char option;
	req_and_res message;
	_Bool is_wait_response = 0;
	long unsigned int _pid = getpid();
	message.pid = _pid;
	show_options();
	scanf("\n%c", &option);
	switch (option) {
		case '1':
			is_wait_response = 1;
			message.request_type = GET_PRODUCTS;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case '2':
			is_wait_response = 1;
			message.request_type = ADD_PRODUCT_TO_CART;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case '3':
			is_wait_response = 1;
			message.request_type = SHOW_CART_CONTENT;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case '4':
			is_wait_response = 1;
			message.request_type = MODIFY_STOCK_FROM_CART;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case '5':
			is_wait_response = 1;
			message.request_type = DELETE_PRODUCT_FROM_CART;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case '6':
			is_wait_response = 1;
			message.request_type = BUY_PRODUCTS;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case '7':
			printf("Hasta luego \n");
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Ingresar una entrada válida \n");
			break;
	}

if (is_wait_response) {
	is_wait_response = 0;
	msgrcv(_response_queue, &message, LENGTH, _pid, 0);
	switch (message.request_type) {
		case GET_PRODUCTS:
			show_products(shop_items,
			message.response_status_code);
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

void show_products(struct shared_memory_shop *_items, unsigned short int status_code){
	if (status_code != 200) {
		printf("%d \n", status_code );
		/*Tratamiento de códigos*/
	}else{
		printf("\e[95m\e[1m\e[7m%-18s %-18s %-18s %-18s \e[0m \n","ID","Producto","Precio","Existencia");
		for (int i = 0; i < MAX_ITEMS; i++) {
			printf("%-18u %-18s %-18f %-18u \n", _items->_items[i].item_id,_items->_items[i].name,_items->_items[i].price,_items->_items[i].stock);
		}
	}
}

void init_queues(int *res_queue, int *req_queue){
	key_t _key;
	_key = ftok(KEY_FILES_FOR_QUEUE, RESPONSE_KEY);
	*res_queue = msgget(_key, IPC_CREAT | 0666 );
	if (*res_queue == -1 ) {
		perror("No se pudo crear la cola de mensajes servidor - cliente");
		exit(EXIT_FAILURE);
	}
	_key = ftok(KEY_FILES_FOR_QUEUE, REQUEST_KEY);
	*req_queue = msgget(_key, IPC_CREAT | 0666 );
	if (*req_queue == -1 ) {
		perror("No se pudo crear la cola de mensajes cliente - servidor");
		exit(EXIT_FAILURE);
	}
}
