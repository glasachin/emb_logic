
cmake_minimum_required(VERSION 3.10)
project(main VERSION 1.0)

add_subdirectory(functions)
add_executable(main main.cxx)

target_link_libraries(main PUBLIC functions)
target_include_directories(main PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/functions"
                            )
