#zero_mq_client_server
#ZeroMQ guide: https://zguide.zeromq.org/docs/chapter1/
#A good answer to fixing CMake and link the ZeroMQ library to CMake: https://stackoverflow.com/questions/41251474/how-to-import-zeromq-libraries-in-cmake

CMake doesn't include direct support for 0mq and 0mq doesn't include direct support for CMake. But, 0mq does support pkg-config and we can use this to help us. Since you mentioned that you're on Ubuntu 14.04, make sure you've done sudo apt-get install libzmq3-dev to install the 0mq libraries, headers, and the pkg-config .pc file.

Then use the following CMakeLists.txt which I've modified from your version above. (I've commented all my changes inline.)

## i have cmake 3.5
cmake_minimum_required(VERSION 3.5)
project(test2)

## use this to globally use C++11 with in our project
set(CMAKE_CXX_STANDARD 11)

## load in pkg-config support
find_package(PkgConfig)
## use pkg-config to get hints for 0mq locations
pkg_check_modules(PC_ZeroMQ QUIET zmq)

## use the hint from above to find where 'zmq.hpp' is located
find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
        )

## use the hint from above to find the location of libzmq
find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
        )

set(SOURCE_FILES main.cpp)
add_executable(test2 ${SOURCE_FILES})

## add the include directory to our compile directives
target_include_directories(test2 PUBLIC ${ZeroMQ_INCLUDE_DIR})
## at the 0mq library to our link directive
target_link_libraries(test2 PUBLIC ${ZeroMQ_LIBRARY})

Now you can make your project.

❯ make
[ 50%] Building CXX object CMakeFiles/test2.dir/main.cpp.o
[100%] Linking CXX executable test2
[100%] Built target test2
