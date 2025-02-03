cmake_minimum_required(VERSION 3.29)
project(zero_mq_client_server C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig)
pkg_check_modules(PC_ZeroMQ QUIET zmq)
find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
)
find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
)


add_executable(zero_mq_client_server zmq_server.c
        )

target_include_directories(zero_mq_client_server PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(zero_mq_client_server PUBLIC ${ZeroMQ_LIBRARY})

add_executable(zero_mq_client zmq_client.c
        )
target_include_directories(zero_mq_client PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(zero_mq_client PUBLIC ${ZeroMQ_LIBRARY})