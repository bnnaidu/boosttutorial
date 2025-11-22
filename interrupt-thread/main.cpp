#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <iostream>

void wait(int seconds) {
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread() {
  int count = 5;
  try {
    for (size_t i = 0; i < count; i++) {
      wait(1);
      std::cout << i << std::endl;
    }
  } catch (boost::thread_interrupted &) {
    std::cout << "thread interrupted\n";
  }
}

int main() {
  boost::thread t{thread};
  wait(3);
  t.interrupt();
  t.join();

  return 0;
}