#include <map>
#include <set>
#include <vector>
using namespace std;

class MyCalendarThree {
 private:
  map<int, vector<int>> m;

 public:
  MyCalendarThree() {}

  int book(int start, int end) {
    m[start].push_back(end);
    multiset<int> s;
    size_t max = 0;
    for (auto &kv : m) {
      int start = kv.first;
      vector<int> &ends = kv.second;
      auto it = s.upper_bound(start);
      if (it == s.end())
        s.clear();
      else
        s.erase(s.begin(), it);
      s.insert(ends.begin(), ends.end());
      if (s.size() > max) max = s.size();
    }
    return max;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
