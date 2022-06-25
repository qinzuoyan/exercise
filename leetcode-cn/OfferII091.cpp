#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& costs) {
    int a[3] = {0}, b[3];
    for (auto & v : costs) {
      b[0] = min(a[1], a[2]) + v[0];
      b[1] = min(a[0], a[2]) + v[1];
      b[2] = min(a[0], a[1]) + v[2];
      memcpy(a, b, sizeof(a));
    }
    return min(min(a[0], a[1]), a[2]);
  }
};
