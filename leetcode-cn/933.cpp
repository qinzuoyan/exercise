#include <deque>
using namespace std;

class RecentCounter {
  deque<int> q;

 public:
  RecentCounter() {}

  int ping(int t) {
    q.push_back(t);
    int s = t - 3000;
    if (q.front() < s) {
      auto it = lower_bound(q.begin(), q.end(), s);
      if (it != q.begin()) q.erase(q.begin(), it);
    }
    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
