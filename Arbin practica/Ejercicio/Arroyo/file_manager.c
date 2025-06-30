#include "file_manager.h"
void get_users(struct user *_user){
	FILE *_file = fopen("./db/users", "r+");
	int user_num = 0;
	if (_file == NULL) {
		fprintf(stderr, "No se pudo conectar a la base de datos\n\e[4;31m\e[1m Error :\e[0m \n");
	}
	while (fscanf(_file, "%u %s %s %f", &_user[user_num].user_id,_user[user_num].username,_user[user_num].password,&_user[user_num].money_to_buy) != EOF) {
		user_num++;
	}
	fclose(_file);
}

void get_products(struct item *_item){
	FILE *_file = fopen("./db/shop", "r+");
	int item_num = 0;
	if (_file == NULL) {
		fprintf(stderr, "No se pudo conectar a la base de datos\n\e[4;31m\e[1m Error :\e[0m \n");
	}
	while (fscanf(_file, "%hu %s %f %u",&_item[item_num].item_id,_item[item_num].name,&_item[item_num].price,&_item[item_num].stock) != EOF) {
		item_num++;
	}
	fclose(_file);
}
