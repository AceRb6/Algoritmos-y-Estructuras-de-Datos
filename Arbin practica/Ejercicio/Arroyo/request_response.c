#include "request_response.h"
struct shared_memory_shop *init_shop_shared_memory(){
	key_t _key;
	int shmid;
	struct shared_memory_shop *item_list;
	_key = ftok(KEY_FILES_FOR_SHM_SHOP, SHM_SHOP_KEY);
	shmid = shmget(_key, sizeof(struct shared_memory_shop*), IPC_CREAT |0600 );
	if (shmid == -1) {
		perror("No se pudo crear la zona de memoria compartida");
		exit(EXIT_FAILURE);
	}
	if( (item_list = (struct shared_memory_shop*)shmat(shmid,0,0)) ==(struct shared_memory_shop *)-1){
		perror("No se pudo enlazar la memoria compartida");
		exit(EXIT_FAILURE);
	}
	item_list->shmid = shmid;
	return item_list;
}

struct shared_memory_cart *init_cart_shared_memory(){
	key_t _key;
	int shmid;
	struct shared_memory_cart *cart;
	_key = ftok(KEY_FILES_FOR_SHM_CART, SHM_CART_KEY);
	shmid = shmget(_key, sizeof(struct shared_memory_cart*), IPC_CREAT |0600 );
	if (shmid == -1) {
		perror("No se pudo crear la zona de memoria compartida");
		exit(EXIT_FAILURE);
	}
	if( (cart = (struct shared_memory_cart*)shmat(shmid,0,0)) == (struct shared_memory_cart *)-1){
		perror("No se pudo enlazar la memoria compartida");
		exit(EXIT_FAILURE);
	}
	cart->shmid = shmid;
	return cart;
}

