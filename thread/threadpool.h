#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "thread.h"
#include "noncopyable.h"
#include <vector>
#include <deque>
#include <memory>

namespace base
{

class ThreadPool
{
  typedef std::function<void ()> Task;
 public:
  ThreadPool(int numthreads,const std::string& name);

  void Run(Task );
  void Start();
  Task Take();
  void Stop();
  void SetMaxTasks(int maxtask) { maxTasks_ = maxtask; }

  ~ThreadPool();

 private:
  void RunTask();
  bool IsFull() const;

  bool running_;
  int threadNUms_;
  std::string name_;
  std::vector<std::unique_ptr<Thread>> threads_;
  Task task_;
  size_t maxTasks_;
  std::deque<Task> tasksQueue_;
  std::mutex mutex_;
  std::condition_variable notFull_;
  std::condition_variable notEmpty_;
};
}




#endif   /* __THREADPOOL_H__ */
