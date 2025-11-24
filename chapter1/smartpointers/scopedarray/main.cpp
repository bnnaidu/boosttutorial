#include <boost/scoped_array.hpp>
#include <iostream>

int main() {
  boost::scoped_array<int> p{new int[2]};
  *p.get() = 1;
  p[1] = 2;
  std::cout << p[1] << std::endl;
  p.reset(new int[3]);
  return 0;
}