#include <deque>
using namespace std;

class MovingAverage {
  deque<int> q;
  int s;
  int sum;

 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) : s(size), sum(0.0) {}

  double next(int val) {
    sum += val;
    q.push_back(val);
    if ((int)q.size() > s) {
      sum -= q.front();
      q.pop_front();
    }
    return (double)sum / q.size();
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
