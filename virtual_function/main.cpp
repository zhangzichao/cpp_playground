#include <iostream>
#include "timer.h"

// dynamic binding
class Base
{
public:
  virtual void doSomeThing() = 0;
};

class Derived: public Base
{
public:
  virtual void doSomeThing()
  {
    int i = 1;
    i++;
  }
};

class Engine
{
public:
  void doSomeThing()
  {
    int i = 1;
    i++;
  }
};

// template engine
template<class T_engine>
class TBase
{
public:
  void doSomeThing()
  { engine_.doSomeThing(); }
private:
  T_engine engine_;
};


int main(int argc, char *argv[])
{
  utils::Timer timer;

  Base* dynamic_bind = new Derived();
  TBase<Engine> static_bind;

  timer.start();
  for(int i=0; i<5000; i++)
    dynamic_bind->doSomeThing();
  timer.stop();
  std::cout << "Dynamic binding: "<< timer.getMilliseconds() << std::endl;

  timer.start();
  for(int i=0; i<5000; i++)
    static_bind.doSomeThing();
  timer.stop();
  std::cout << "Static binding: "<< timer.getMilliseconds() << std::endl;

  return 0;
}
