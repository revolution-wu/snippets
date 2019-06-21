/**************************************************************************
 *      FileName: countdownlatch.cpp
 * 
 *        Author: 
 *   Description: ---
 *  Created Time: 2019年03月18日 星期一 13时11分40秒
 * Last Modified: 2019-03-18 13:11:40
 * 
 **************************************************************************/
#include "countdownlatch.h"

using namespace base;
CountDownLatch::CountDownLatch(int count)
  :count_(count)
{

}

CountDownLatch::~CountDownLatch()
{}

void CountDownLatch::CountDown()
{
  std::unique_lock<std::mutex> lock(mutex_);
  --count_;
  if(count_ == 0)
  {
    cond_.notify_all();
  }
}

void CountDownLatch::Wait()
{
  std::unique_lock<std::mutex> lock(mutex_);
  while(count_ > 0)
  {
    cond_.wait(lock);
  }
}

int CountDownLatch::GetCount() const
{
  std::lock_guard<std::mutex> lock(mutex_);
  return count_;
}
