#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void wait(int seconds) {
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

boost::shared_mutex mutex;
std::vector<int> random_numbers;

void fill() {
  std::srand(static_cast<unsigned int>(std::time(0)));
  random_numbers.reserve(3);
  for (size_t i = 0; i < 3; i++) {
    boost::unique_lock<boost::shared_mutex> lock{mutex};
    random_numbers.push_back(std::rand());
    std::cout << i << ": " << random_numbers.back() << std::endl;
    lock.unlock();
    wait(1);
  }
}

void print() {
  for (size_t i = 0; i < 3; i++) {
    wait(1);
    boost::shared_lock<boost::shared_mutex> lock{mutex};
    std::cout << random_numbers.back() << std::endl;
  }
}

int sum = 0;

void count() {
  for (size_t i = 0; i < 3; i++) {
    wait(1);
    boost::shared_lock<boost::shared_mutex> lock{mutex};
    sum += random_numbers.back();
  }
}

int main() {
  boost::thread t1{fill}, t2{print}, t3{count};
  t1.join();
  t2.join();
  t3.join();

  std::cout << "sum: " << sum << std::endl;
  return 0;
}