#include <vector>
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int a[n], sum = 0, max = 0;
    for (int i = 0; i < n; i++) {
      a[i] = gas[i] - cost[i];
      sum += a[i];
      if (a[i] > max) {
        max = a[i];
      }
    }
    if (sum < 0) {
      return -1;
    }
    if (max == 0) {  // all 0
      return 0;
    }
    int s = -1, i = 0, k = n;
    while (k--) {
      if (s == -1) {
        if (a[i] > 0) {
          s = i;
        }
      } else {  // s != -1
        if (a[s] + a[i] >= 0) {
          if (a[i] != 0) {
            a[s] += a[i];
            a[i] = 0;
            k = n;
          }
        } else {
          s = -1;
        }
      }
      i = (i + 1) % n;
    }
    return s;
  }
};
