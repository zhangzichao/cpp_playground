#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h> // TODO: paltform specific

void subThread(int thread_id)
{
  for(int i=0; i<5; i++)
    std::cout << "From thread " << thread_id
             << ": " << i << std::endl;
  std::cout << "Return of thread " << thread_id << std::endl;
}

void infiteSubThread()
{
  while(true)
  {}
  // never reach here
  std::cout << "Inifite done\n";
}

void anotherThread()
{
  // observer
  std::cout << "there're " << std::thread::hardware_concurrency()
            << " concurrent threads allowed on this machine.\n";
  // without the detach call here,
  //   the program will ne terminated as soon as this method returns
  std::thread inner(infiteSubThread);
  inner.detach();
  std::cout << "End of thread creator.\n";
}

int main(int argc, char *argv[])
{
  // Once initialized, it starts execution
  std::thread thread1(subThread, 1);
  std::thread thread2(subThread, 2);

  // sleep for 2 seconds, you can see threads output
  sleep(2);

  std::cout << "thread1 is joinable? " << thread1.joinable() << std::endl;
  std::cout << "thread2 is joinable? " << thread2.joinable() << std::endl;

  // here are some thread that never returns
  std::thread infinite_thread(infiteSubThread);
  std::thread thread_creator(anotherThread);

  // detach
  // use detach when you don't care when the threads will end
  // detached threads will be terminated when the process die
//  thread1.detach();
//  thread2.detach();
  infinite_thread.detach();

  // join
  // use join() when you want to make sure the threads ended before the end
  thread1.join();
  thread_creator.join();
  thread2.join();
//  infinite_thread.join(); // this will never end

  // NOTE: if a thread that is joinable(not joined and detached) goes out of scope
  // terminate will be called(via ~thread), which is certainly not desired.

  std::cout << "thread1 is joinable? " << thread1.joinable() << std::endl;
  std::cout << "thread2 is joinable? " << thread2.joinable() << std::endl;
  std::cout << "infinite_thread is joinable? "
            << infinite_thread.joinable() << std::endl;

  std::cout << "End of main.\n";
  return 0;
}
