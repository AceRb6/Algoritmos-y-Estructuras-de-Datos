#include "../file_manager/file_manager.h"
#include "../request_response.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
void init_queues(int *res_queue, int *req_queue);
struct user *init_users_structures();
void wait_request(int _request_queue, int _response_queue);
