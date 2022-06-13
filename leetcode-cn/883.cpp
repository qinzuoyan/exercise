#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  int projectionArea(vector<vector<int>> &grid) {
    int n = grid.size();
    int y[n], z[n], r = 0;
    memset(y, 0, sizeof(y));
    memset(z, 0, sizeof(z));
    for (int i = 0; i < n; ++i) {
      vector<int> &v = grid[i];
      for (int j = 0; j < n; ++j) {
        int k = v[j];
        if (k) {
          ++r;
          if (k > y[i]) {
            r += k - y[i];
            y[i] = k;
          }
          if (k > z[j]) {
            r += k - z[j];
            z[j] = k;
          }
        }
      }
    }
    return r;
  }
};
