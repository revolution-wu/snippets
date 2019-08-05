
project(thread C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g -Wall -O0 -Wno-unused-variable -pthread") 
set(CMAKE_CXX_COMPILER "g++")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


set(LISTSRC
  thread.cpp
  threadpool.cpp
  countdownlatch.cpp
  buffer.cpp
  )

add_library(base ${LISTSRC})

add_subdirectory(test)



