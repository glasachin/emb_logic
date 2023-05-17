cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(main VERSION 1.0)


# TODO 2: Use add_subdirectory() to add MathFunctions to this project
add_subdirectory(functions)

# add the executable
add_executable(main main.cxx)

# TODO 3: Use target_link_libraries to link the library to our executable
target_link_libraries(main PUBLIC functions)

target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_BINARY_DIR}/functions"
                           )
