#include <algorithm>
#include <boost/bind/bind.hpp>
#include <boost/bind/placeholders.hpp>
#include <iostream>
#include <vector>

void printNum(int x) { std::cout << x << std::endl; }

int main() {
  std::vector<int> nums{1, 2, 3, 4, 5};
  using namespace boost::placeholders;

  std::for_each(nums.begin(), nums.end(), boost::bind(&printNum, _1));

  return 0;
}