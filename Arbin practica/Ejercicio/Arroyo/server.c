#include "server.h"
void wait_request(int _request_queue, int _response_queue){
	req_and_res message;
	msgrcv(_request_queue, &message, LENGTH, 0, 0);
	switch (message.request_type) {
		case GET_PRODUCTS:
			printf("Petición recibida del cliente %lu \n",message.pid);
			printf("Enviar productos \n");
			message.response_status_code = 200;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case ADD_PRODUCT_TO_CART:
			printf("Petición recibida del cliente %lu \n",message.pid);
			printf("Agregar producto al carrito \n");
			message.response_status_code = 200;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case SHOW_CART_CONTENT:
			printf("Petición recibida del cliente %lu \n",message.pid);
			printf("Mostrar contenido del carrito \n");
			message.response_status_code = 200;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case MODIFY_STOCK_FROM_CART:
			printf("Petición recibida del cliente %lu \n",message.pid);
			printf("Modificar cantidad de producto \n");
			message.response_status_code = 200;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case DELETE_PRODUCT_FROM_CART:
			printf("Petición recibida del cliente %lu \n",message.pid);
			printf("Eliminar producto del carrito \n");
			message.response_status_code = 200;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		case BUY_PRODUCTS:
			printf("Petición recibida del cliente %lu \n",message.pid);
			printf("Comprar productos \n");
			message.response_status_code = 200;
			msgsnd(_request_queue, &message, LENGTH, 0);
			break;
		default:
			msgctl(_request_queue, IPC_RMID, 0);
			msgctl(_response_queue, IPC_RMID, 0);
			printf("Error \n");
			exit(EXIT_FAILURE);
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

struct user *init_users_structures(){
	struct user *user_list = NULL;
	user_list = (struct user*)malloc(MAX_USERS*sizeof(struct user));
	return user_list;
}

