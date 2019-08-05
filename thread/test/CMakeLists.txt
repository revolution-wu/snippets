add_executable(thread_test thread_test.cpp)
target_link_libraries(thread_test base)

add_executable(threadpool_test threadpool_test.cpp)
target_link_libraries(threadpool_test base)

add_executable(buffer_test buffer_test.cpp)
target_link_libraries(buffer_test base)

add_executable(echoserver_test echoserver_test.cpp)
target_link_libraries(echoserver_test base)
