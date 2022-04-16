#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;

class FooBar {
 private:
  int n;
  mutex mtx;
  condition_variable cv;
  int c;

 public:
  FooBar(int n) {
    this->n = n;
    this->c = 0;
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> lck(mtx);
      while (c != 0) cv.wait(lck);

      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();

      c = 1;
      cv.notify_all();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> lck(mtx);
      while (c != 1) cv.wait(lck);

      // printBar() outputs "bar". Do not change or remove this line.
      printBar();

      c = 0;
      cv.notify_all();
    }
  }
};
