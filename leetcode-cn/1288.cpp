#include <algorithm>
#include <vector>
using namespace std;

bool compare1288(const vector<int> &a, const vector<int> &b) {
  if (a[0] < b[0]) return true;
  if (a[0] > b[0]) return false;
  return a[1] > b[1];
}

class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), compare1288);
    int r = 1, i = 1, k = 0, n = intervals.size();
    while (i < n) {
      if (intervals[i][1] > intervals[k][1]) {
        r++;
        k = i;
      }
      i++;
    }
    return r;
  }
};
