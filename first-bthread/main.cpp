#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <iostream>

void wait(int seconds) {
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}
void thread() {
  for (size_t i = 0; i < 5; i++) {
    wait(1);
    std::cout << i << std::endl;
  }
}
int main() {
  boost::thread t{thread};
  t.join();
  return 0;
}