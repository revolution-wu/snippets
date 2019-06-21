/**************************************************************************
 *      FileName: threadpool.cpp
 * 
 *        Author: 
 *   Description: ---
 *  Created Time: 2019年03月12日 星期二 16时08分08秒
 * Last Modified: 2019-03-12 16:08:08
 * 
 **************************************************************************/
#include "threadpool.h"
#include <assert.h>

using namespace base;

ThreadPool::ThreadPool(int numthreads,const std::string& name)
  :running_(false),
  threadNUms_(numthreads),
  name_(name),
  maxTasks_(0)
{

}

ThreadPool::~ThreadPool()
{
  if(running_)
  {
    Stop();
  }
}
void ThreadPool::Start()
{
  assert(!running_);
  running_ = true;
  
  if(threads_.empty())
    threads_.reserve(threadNUms_);

  for(int i = 0; i < threadNUms_; ++i)
  {
    char buf[32];
    snprintf(buf, sizeof buf, "%s%d", name_.c_str(), i + 1);
    threads_.push_back(std::unique_ptr<Thread>(new Thread(std::bind(&ThreadPool::RunTask, this),name_)));
    threads_[i]->Start();
  }
}

void ThreadPool::Stop()
{
  {
    std::lock_guard<std::mutex> lock(mutex_);
    running_ = false;
    notEmpty_.notify_all();
  }
  for(auto& th : threads_)
  {
    th->Join();  
  }
}
void ThreadPool::Run(Task task)
{
  if(threads_.empty())
  {
    task();
  }
  else
  {
    while(IsFull())
    {
    }
    tasksQueue_.push_back(task);
    notEmpty_.notify_one();
  }
}

ThreadPool::Task ThreadPool::Take()
{
  std::unique_lock<std::mutex> lock(mutex_);
  while(tasksQueue_.empty() && running_)
  {
    notEmpty_.wait(lock);
  }
  Task take;
  if(!tasksQueue_.empty())
  {
    take = tasksQueue_.front();
    tasksQueue_.pop_front();
    if(maxTasks_ > 0)
      notFull_.notify_one();
  }
  return take;

}

bool ThreadPool::IsFull() const
{
  return maxTasks_ > 0 && tasksQueue_.size() >= maxTasks_;
}

void ThreadPool::RunTask()
{
  while(running_)
  {
    Task task(Take());
    if(task)
      task();
  }
}
