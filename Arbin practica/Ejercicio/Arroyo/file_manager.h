#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20
#define MAX_USERS 7
#define MAX_ITEMS 6
struct user{
	unsigned int user_id;
	char username[MAX_LENGTH];
	char password[MAX_LENGTH];
	float money_to_buy;
};

struct item{
	int shmid;
	unsigned short int item_id;
	char name[MAX_LENGTH];
	float price;
	unsigned int stock;
};

struct shared_memory_cart{
	int shmid;
	unsigned int user_id;
	struct item _items[MAX_ITEMS];
};

struct shared_memory_shop{
	int shmid;
	struct item _items[MAX_ITEMS];
};

void get_users(struct user *_user);
void get_products(struct item *_item);
//void insert_items_in_cart(FILE *file, struct items_in_cart);
//void fill_files();
#endif
