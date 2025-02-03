// Hello World Server

#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "zhelpers.h"

int main(int argc, char **argv) {
    // Socket to talk to clients
    void *context = zmq_ctx_new();
    void *responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://localhost:5555");
    assert(rc == 0);

    while(1) {
        char buffer [10];
        zmq_recv(responder, buffer, 10, 0); //enough buffer to handle Hello 0...\0
        printf("Received Hello\n");
        sleep(1);       // Do some 'work'
        zmq_send(responder, "This is a message from CS361", 28, 0);
    }
    return 0;
}
