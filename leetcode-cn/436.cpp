#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int n = intervals.size();
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
      m[intervals[i][0]] = i;
    }
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
      auto it = m.lower_bound(intervals[i][1]);
      r[i] = (it == m.end() ? -1 : it->second);
    }
    return r;
  }
};
