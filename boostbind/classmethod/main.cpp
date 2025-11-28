#include <algorithm>
#include <boost/bind/bind.hpp>
#include <boost/bind/placeholders.hpp>
#include <iostream>
#include <vector>

class Printer {
public:
  void printNum(int x) const { std::cout << x << std::endl; }
};

int main() {
  Printer p;
  std::vector<int> nums{1, 2, 3, 4, 5};
  using namespace boost::placeholders;

  std::for_each(nums.begin(), nums.end(),
                boost::bind(&Printer::printNum, &p, _1));

  return 0;
}