#include <future>
#include <iostream>
#include <timer.h>
#include <vector>

namespace
{
int sum(int lo, int hi)
{
  int sum = 0;
  for(int i=lo; i<=hi; i++)
    sum += i;
  return sum;
}

int async_sum(int lo, int hi, int N)
{
  std::vector<std::future<int> > results;
  int interval = (hi-lo+1) / N; // how many numbers to add
  for(int i=0; i<N; i++)
  {
    int inter_lo = lo + i*interval;
    int inter_hi = (i==N-1? hi : inter_lo+interval-1);
    results.push_back(std::async(sum, inter_lo, inter_hi));
  }
  int sum = 0;
  for(auto& res : results)
    sum += res.get();
  return sum;
}
}

int main(int argc, char *argv[])
{
  int N = std::numeric_limits<int>::max()/2;
  int async_num = 4;

  utils::Timer timer;
  timer.start();
  int sum_serial = sum(0, N);
  timer.stop();
  std::cout << "Serial version add: " << timer.getMilliseconds()
            << "ms\n";
  std::cout << "Sum: " << sum_serial << std::endl;

  timer.reset();
  timer.start();
  int sum_async = async_sum(0, N, async_num);
  timer.stop();
  std::cout << "Async version add: " << timer.getMilliseconds()
            << "ms\n";
  std::cout << "Sum: " << sum_async << std::endl;

  return 0;
}
