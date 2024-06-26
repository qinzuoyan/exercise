#include <vector>
using namespace std;

class Solution {
public:
  int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    int n = startTime.size();
    int r = 0;
    for (int i = 0; i < n; ++i) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i])
        ++r;
    }
    return r;
  }
};
