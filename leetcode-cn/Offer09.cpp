#include <stack>
using namespace std;

class CQueue {
  stack<int> t, h;

public:
  CQueue() {}

  void appendTail(int value) { t.push(value); }

  int deleteHead() {
    if (h.empty()) {
      if (t.empty()) {
        return -1;
      } else {
        while (t.size()) {
          h.push(t.top());
          t.pop();
        }
      }
    }
    int r = h.top();
    h.pop();
    return r;
  }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
