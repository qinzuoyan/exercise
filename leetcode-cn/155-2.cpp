#include <stack>
#include <utility>
using namespace std;

class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    if (_s.empty())
      _s.emplace(val, val);
    else
      _s.emplace(val, min(val, _s.top().second));
  }

  void pop() { _s.pop(); }

  int top() { return _s.top().first; }

  int getMin() { return _s.top().second; }

 private:
  stack<pair<int, int>> _s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
