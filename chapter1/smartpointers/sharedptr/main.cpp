#include <boost/shared_ptr.hpp>
#include <iostream>

int main() {
  boost::shared_ptr<int> p1{new int{1}};
  std::cout << *p1 << std::endl;
  boost::shared_ptr<int> p2{p1};
  p1.reset(new int{2});
  std::cout << *p1.get() << std::endl;
  p1.reset();
  std::cout << *p2 << std::endl;
  std::cout << std::boolalpha << static_cast<bool>(p2) << std::endl;
  return 0;
}