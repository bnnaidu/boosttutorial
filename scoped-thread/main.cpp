#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <iostream>

void wait(int seconds) {
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread() {
  int count = 5;
  for (size_t i = 0; i < count; i++) {
    wait(1);
    std::cout << i << std::endl;
  }
}
int main() {
  boost::scoped_thread<> t{boost::thread{thread}};
  return 0;
}