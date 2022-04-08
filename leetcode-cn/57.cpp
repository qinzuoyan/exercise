#include <vector>
using namespace std;

class Solution {
 public:
  // O(n)
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> r;
    int i = 0, n = intervals.size();
    while (i < n && intervals[i][1] < newInterval[0]) i++;
    r.insert(r.end(), intervals.begin(), intervals.begin() + i);
    while (i < n && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }
    r.push_back(newInterval);
    r.insert(r.end(), intervals.begin() + i, intervals.end());
    return r;
  }
};
