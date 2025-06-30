#ifndef _REQUEST_RESPONSE_H_
#define _REQUEST_RESPONSE_H_
#include "file_manager/file_manager.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY_FILES_FOR_QUEUE "../request_response.h"
#define KEY_FILES_FOR_SHM_SHOP "./db/shop"
#define KEY_FILES_FOR_SHM_CART "./db/carts"
#define SHM_SHOP_KEY 'S' // SHOP KEY SHARED MEMORY
#define SHM_CART_KEY 'C' // SHOP KEY SHARED MEMORY
#define RESPONSE_KEY 'K' // QUEUE KEY FOR RESPONSE
#define REQUEST_KEY 'L' // QUEUE KEY FOR REQUEST
#define GET_PRODUCTS 'a'
#define ADD_PRODUCT_TO_CART 'b'
#define SHOW_CART_CONTENT 'c'
#define MODIFY_STOCK_FROM_CART 'd'
#define DELETE_PRODUCT_FROM_CART 'l'
#define BUY_PRODUCTS 'f'
typedef struct req_and_res{
	long pid;
	char request_type;
	unsigned int user_id;
	unsigned short int response_status_code;
}req_and_res;
#define LENGTH (sizeof(struct req_and_res) - sizeof(long))
struct shared_memory_shop *init_shop_shared_memory();
struct shared_memory_cart *init_cart_shared_memory();
#endif
