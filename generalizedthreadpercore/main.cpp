#include <boost/thread.hpp>
#include <cctype>
#include <iostream>
#include <vector>

void worker() {
  std::uint64_t total = 0;
  for (size_t i = 0; i < 1'000'000'000; i++) {
    total += i;
  }
  std::cout << total << std::endl;
}

int main() {
  int cpucores = boost::thread::hardware_concurrency();
  if (cpucores == 0)
    cpucores = 2;
  std::cout << "Lanunching " << cpucores << " threads...\n";

  std::vector<boost::thread> threads;
  threads.reserve(cpucores);

  for (int i = 0; i < cpucores; i++) {
    threads.emplace_back(worker);
  }
  for (auto &t : threads) {
    t.join();
  }
  std::cout << "All threads completed...\n";
  return 0;
}