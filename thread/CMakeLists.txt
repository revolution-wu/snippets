
project(thread C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g -Wall -O0 -Wno-unused-variable -pthread") 
set(CMAKE_CXX_COMPILER "g++")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


set(LISTSRC
  thread.cpp
<<<<<<< HEAD
  threadpool.cpp
  countdownlatch.cpp
  )

add_library(base ${LISTSRC})

add_subdirectory(test)
=======
  test/thread_test.cpp)

add_executable(thread_test ${LISTSRC})

>>>>>>> e71df5385141000f7d516b8c0f307153f08b2658

