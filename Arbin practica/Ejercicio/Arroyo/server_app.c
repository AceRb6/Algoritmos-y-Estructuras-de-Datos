#include "server.h"
int main() {
	struct user *user_list = NULL;
	struct shared_memory_shop *shop_items = NULL;
	int res_queue, req_queue;
	init_queues(&res_queue, &req_queue);
	user_list = init_users_structures();
	shop_items = init_shop_shared_memory();
	get_users(user_list);
	get_products(shop_items->_items);
	while (1) {
		wait_request(req_queue, res_queue);
	}
	return 0;
}

