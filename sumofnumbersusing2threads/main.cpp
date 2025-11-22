#include <boost/timer/timer.hpp>
#include <cstdint>
#include <iostream>

int main() {
  boost::timer::cpu_timer timer;
  std::uint64_t total = 0;
  for (int i = 0; i < 1'000'000'000; i++) {
    total += i;
  }
  std::cout << timer.format() << std::endl;
  std::cout << total << std::endl;

  return 0;
}