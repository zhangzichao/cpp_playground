#include <iostream>
#include <timer.h>

int main(int argc, char *argv[])
{
  utils::Timer timer;
  int sum = 0;

  std::cout << "Test for array access, add with different stride:\n";

  int array1[4000];
  timer.start();
  for(int i=0; i<4000; i++)
    sum += array1[i];
  timer.stop();
  std::cout << "Time for stride 1: "
            << timer.getMilliseconds() << "ms"<< std::endl;

  sum = 0;
  int array8[4000][8];
  timer.start();
  for(int i=0; i<4000; i++)
    sum += array8[i][0];
  timer.stop();
  std::cout << "Time for stride 8: "
            << timer.getMilliseconds() << "ms"<< std::endl;

  sum = 0;
  int array16[4000][16];
  timer.start();
  for(int i=0; i<4000; i++)
  {
    sum += array16[i][0];
  }
  timer.stop();
  std::cout << "Time for stride 16: "
            << timer.getMilliseconds() << "ms"<< std::endl;

  return 0;
}
