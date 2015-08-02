#include <iostream>
#include "timer.h"

// dynamic binding
class Base
{
public:
  virtual void doSomeThing() { int i=1; i++; };
};

class Derived1: public Base
{
public:
  virtual void doSomeThing()
  {
    int i = 1;
    i++;
  }
};

class Derived2: public Base
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

// CRTP
template<class Impl>
class CRTPBase
{
public:
  void doSomeThing()
  { static_cast<Impl*>(this)->doSomeThing(); }
};

class CRTPImpl : public CRTPBase<CRTPImpl>
{
public:
  void doSomeThing()
  { int i=1; i++; }
};

template<class T_CRTP_Impl>
inline void runCRTP(CRTPBase<T_CRTP_Impl>& crtp)
{
  utils::Timer timer;
  timer.start();
  for(int i=0; i<5000; i++)
    crtp.doSomeThing();
  timer.stop();
  std::cout << "CRTP: "<< timer.getMilliseconds() << std::endl;
}


int main(int argc, char *argv[])
{
  utils::Timer timer;

  Base& dynamic_bind = *(new Derived1());
  TBase<Engine> static_bind;
  CRTPImpl crtp_impl;

  timer.start();
  for(int i=0; i<5000; i++)
    dynamic_bind.doSomeThing();
  timer.stop();
  std::cout << "Dynamic binding: "<< timer.getMilliseconds() << std::endl;
  delete &dynamic_bind;

  timer.start();
  for(int i=0; i<5000; i++)
    static_bind.doSomeThing();
  timer.stop();
  std::cout << "Static binding: "<< timer.getMilliseconds() << std::endl;

  runCRTP(crtp_impl);

  return 0;
}
