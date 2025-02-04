//
// Created by lora on 2/1/25.
//
// Hello World client
#include <stdio.h>
#include <zmq.h>
#include <string.h>
#include <unistd.h>
#include "zhelpers.h"

int main(void) {
    printf("Connecting to server at port 5555...\n");
    void *context = zmq_ctx_new();
    void *requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");

    int requester_number;

    for(requester_number = 0; requester_number != 10; requester_number++) {
        char buffer[30];
        printf("Sending Hello %d...\n", requester_number);
        s_send(requester, "Hello");
        s_recv(requester);
        printf("Received This is a message from CS361 %d\n", requester_number);
    }
    zmq_close(requester);
    zmq_ctx_destroy(context);
    return 0;
}