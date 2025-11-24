#include <boost/scoped_ptr.hpp>
#include <iostream>

int main() {
  boost::scoped_ptr<int> p{new int{1}};
  std::cout << *p << std::endl;
  p.reset(new int{2});
  std::cout << *p.get() << std::endl;
  p.reset();

  std::cout << std::boolalpha << static_cast<bool>(p) << std::endl;
  return 0;
}