#include <algorithm>
#include <vector>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
  if (a[0] < b[0]) return true;
  if (a[0] > b[0]) return false;
  return a[1] > b[1];
}

class Solution {
 public:
  // O(nlog(n))
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    vector<vector<int>> r;
    vector<int> v = intervals[0];
    for (size_t i = 1; i < intervals.size(); i++) {
      vector<int>& t = intervals[i];
      if (t[0] > v[0]) {
        if (t[0] > v[1]) {
          r.emplace_back(move(v));
          v = t;
        } else if (t[1] > v[1]) {
          v[1] = t[1];
        }
      }
    }
    r.emplace_back(move(v));
    return r;
  }
};
