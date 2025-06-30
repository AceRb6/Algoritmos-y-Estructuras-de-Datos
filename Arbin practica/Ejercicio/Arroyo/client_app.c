#include "client.h"
int main(int argc, char const *argv[]) {
	int _request_queue, _response_queue;
	init_queues(&_request_queue, &_response_queue);
	struct shared_memory_shop *shop_items = NULL;
	shop_items = init_shop_shared_memory();
	while (1) {
		send_request(_request_queue, _response_queue,shop_items);
	}
	return 0;
}
