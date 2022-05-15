#include <map>
using namespace std;

class CountIntervals {
  map<int, int> m;
  int c;

  // return sweeped count and new right
  int sweep(map<int, int>::iterator it, int left, int* right) {
    auto it0 = it;
    int r = 0;
    while (it != m.end() && it->first <= *right) {
      r += it->second - it->first + 1;
      ++it;
    }
    --it;
    *right = max(*right, it->second);
    ++it;
    m.erase(it0, it);
    return r;
  }

 public:
  CountIntervals() : c(0) {}

  void add(int left, int right) {
    if (m.empty()) {
      m.emplace(left, right);
      c += right - left + 1;
      return;
    }
    auto it = m.upper_bound(left);
    if (it == m.begin()) {
      if (it->first <= right) {
        c -= sweep(it, left, &right);
      }
      c += right - left + 1;
      m[left] = right;
    } else {  // it != m.begin()
      --it;
      if (it->second >= left) {
        left = it->first;
        right = max(right, it->second);
        c -= sweep(it, left, &right);
        c += right - left + 1;
        m[left] = right;
      } else {  // it->second < left
        ++it;
        if (it != m.end() && it->first <= right) {
          c -= sweep(it, left, &right);
        }
        c += right - left + 1;
        m[left] = right;
      }
    }
  }

  int count() { return c; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
