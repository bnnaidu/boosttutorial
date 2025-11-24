#include <boost/make_shared.hpp>
#include <iostream>
#include <typeinfo>

int main() {
  auto p1 = boost::make_shared<int>(1);
  std::cout << typeid(p1).name() << std::endl;
  auto p2 = boost::make_shared<int[]>(10);
  std::cout << typeid(p2).name() << std::endl;

  return 0;
}