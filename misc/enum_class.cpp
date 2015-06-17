#include <iostream>

namespace {
enum class Number
{
  kOne, kTwo, kThree
};
enum class UserNumber
{
  kTwo=2, kOne=1, kThree=3
};
}


int main(int argc, char *argv[])
{
  std::cout << "test default enum class:\n";
  Number num1 = Number::kOne;
  Number num1_1 = Number::kOne;
  Number num2 = Number::kTwo;
  if(num1 < num2)
    std::cout << "compare two enum class object: 1<2.\n";
  if(num1 == num1_1)
    std::cout << "two enum class equal: 1==1\n";
  if(num2 < Number::kThree)
    std::cout << "compare enum class object and label: 2<3\n";

  std::cout << "test user assinged enum class:\n";
  UserNumber unum1 = UserNumber::kOne;
  UserNumber unum2 = UserNumber::kTwo;
  UserNumber unum3 = UserNumber::kThree;
  if(unum1 < unum2)
    std::cout << "compare two enum class object: 1<2\n";
  if(unum2 < UserNumber::kThree)
    std::cout << "compare enum class object and label: 2<3\n";

  return 0;
}

