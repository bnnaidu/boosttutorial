#include <boost/thread.hpp>
#include <iostream>

boost::mutex mutex;
void init() {
  static boost::thread_specific_ptr<bool> tls;
  if (!tls.get()) {
    tls.reset(new bool{true});
    boost::lock_guard<boost::mutex> lock{mutex};
    std::cout << "done!..." << std::endl;
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