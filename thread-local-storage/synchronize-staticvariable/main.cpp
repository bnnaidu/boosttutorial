#include <boost/thread.hpp>
#include <iostream>

boost::mutex mutex;

void init() {
  static bool done = false;
  boost::lock_guard<boost::mutex> lock{mutex};
  if (!done) {
    done = true;
    std::cout << "done" << std::endl;
  }
}

void thread() {
  init();
  init();
}

int main() {
  boost::thread t[3];
  for (size_t i = 0; i < 3; i++) {
    t[i] = boost::thread{thread};
  }

  for (size_t i = 0; i < 3; i++) {
    t[i].join();
  }

  return 0;
}