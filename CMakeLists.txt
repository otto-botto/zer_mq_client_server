cmake_minimum_required(VERSION 3.29)
project(zero_mq_client_server C)

set(CMAKE_C_STANDARD 11)

add_executable(zero_mq_client_server zmq_server.c)
