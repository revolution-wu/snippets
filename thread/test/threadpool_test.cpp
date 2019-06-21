#include "../threadpool.h"
#include "../countdownlatch.h"
#include <stdio.h>
#include <unistd.h>

using namespace base;
void print()
{
  printf("tid=%d\n", CurrentThread::Tid());

}

void printString(const std::string& str)
{
   printf("str: %s\n", str.c_str());
  usleep(100*1000);

}

void test(int maxSize)
{
   printf( "Test ThreadPool with max queue size = %d\n" , maxSize);
  ThreadPool pool(5,"MainThreadPool");
  pool.SetMaxTasks(maxSize);
  pool.Start();

  printf("Adding\n");
  pool.Run(print);
  pool.Run(print);
  for (int i = 0; i < 100; ++i)
  {
    char buf[32];
    snprintf(buf, sizeof buf, "task %d", i);
    pool.Run(std::bind(printString, std::string(buf)));

  }
  printf("Done\n");
  
  CountDownLatch latch(1);
  pool.Run(std::bind(&CountDownLatch::CountDown, &latch));
  latch.Wait();
  pool.Stop();
}
int main(int argc, char *argv[])
{
  test(0);
  test(1);
  test(5);
  test(10);
  test(50);
  test(100);
  return 0;
}
