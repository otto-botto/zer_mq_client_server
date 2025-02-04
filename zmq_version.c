//
// Created by lora on 2/3/25.
//
#include <zmq.h>

int main(void) {
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    printf("Current 0MQ version %d.%d.%d\n", major, minor, patch);
    return 0;
}