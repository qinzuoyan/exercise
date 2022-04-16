#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;

class Foo {
 private:
  mutex _mtx;
  condition_variable _cv2;
  condition_variable _cv3;
  bool _ready2;
  bool _ready3;

 public:
  Foo() : _ready2(false), _ready3(false) {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();

    unique_lock<std::mutex> lck(_mtx);
    _ready2 = true;
    _cv2.notify_all();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lck(_mtx);
    while (!_ready2) {
      _cv2.wait(lck);
    }

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();

    _ready3 = true;
    _cv3.notify_all();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> lck(_mtx);
    while (!_ready3) {
      _cv3.wait(lck);
    }

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
