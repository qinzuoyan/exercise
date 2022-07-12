#include <vector>
using namespace std;

class Solution {
 public:
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<vector<int>> a(m, vector<int>(n));
    for (auto& v : indices) {
      int r = v[0], c = v[1];
      for (int j = 0; j < n; ++j) ++a[r][j];
      for (int i = 0; i < m; ++i) ++a[i][c];
    }
    int r = 0;
    for (auto& v : a) {
      for (auto i : v) {
        if (i & 1) ++r;
      }
    }
    return r;
  }
};
