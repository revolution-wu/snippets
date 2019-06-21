#ifndef __COUNTDOWNLATCH_H__
#define __COUNTDOWNLATCH_H__
#include <mutex>
#include <condition_variable>

namespace base
{
class CountDownLatch
{
 public:
  CountDownLatch(int count);
  ~CountDownLatch();
  void Wait();
  void CountDown();
  int GetCount() const;
 private:
  mutable std::mutex mutex_;
  std::condition_variable cond_;
  int count_;
};
}




#endif   /* __COUNTDOWNLATCH_H__ */
