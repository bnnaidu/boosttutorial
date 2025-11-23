#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <iostream>

void wait(int seconds) {
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

boost::mutex mutex;
void worker() {
  using boost::this_thread::get_id;
  for (size_t i = 0; i < 5; i++) {
    wait(1);
    boost::lock_guard<boost::mutex> lock(mutex);
    std::cout << "Thread Id: " << get_id() << ": " << i << std::endl;
  }
}

int main() {
  boost::thread t1{worker};
  boost::thread t2{worker};

  t1.join();
  t2.join();
  return 0;
}