
cmake_minimum_required(VERSION 3.10)
project(main VERSION 1.0)

option(USE_MYMATH "Use tutorial provided math implementation" ON) #creating variable

configure_file(TutorialConfig.h.in TutorialConfig.h)
if(USE_MYMATH)
  add_subdirectory(functions)
  list(APPEND EXTRA_LIBS functions)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/functions")
endif()


add_executable(main main.cxx)

#target_link_libraries(main PUBLIC functions)
target_link_libraries(main PUBLIC ${EXTRA_LIBS})

#target_include_directories(main PUBLIC
#                           "${PROJECT_BINARY_DIR}"
#                            "${PROJECT_SOURCE_DIR}/functions"
#                            )

target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
