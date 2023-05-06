cmake_minimum_required(VERSION 3.12)

add_executable(hello_cpp hello_world.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#project(demo_cpp)
project(demo_cpp VERSION 1.0) # project version number

configure_file(config.h.in config.h) #defining varialbes related to version number

target_include_directories(hello_cpp PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )