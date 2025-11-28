#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums{1, 2, 3, 4, 5};
  std::for_each(nums.begin(), nums.end(),
                [](int x) { std::cout << x << std::endl; });
  return 0;
}