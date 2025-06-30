#ifndef _CLIENT_H_
#define _CLIENT_H_
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../request_response.h"
void init_queues(int *res_queue, int *req_queue);
void send_request(int _request_queue, int _response_queue, struct
shared_memory_shop*);
#endif
