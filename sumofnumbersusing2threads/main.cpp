#include <boost/thread.hpp>
#include <boost/timer/timer.hpp>
#include <cstdint>
#include <iostream>

void thread() {
  boost::timer::cpu_timer timer;
  std::uint64_t total = 0;
  for (int i = 0; i < 1'000'000'000; i++) {
    total += i;
  }
  std::cout << timer.format() << std::endl;
  std::cout << total << std::endl;
}

int main() {
  boost::thread t1{thread};
  boost::thread t2{thread};

  t1.join();
  t2.join();

  return 0;
}