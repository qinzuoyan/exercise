#include <vector>
using namespace std;

class Solution {
 public:
  const int Pacific = 0x1;
  const int Atlantic = 0x2;
  const int PacificAtlantic = 0x3;
  void travel(vector<vector<int>> &h, vector<vector<int>> &a, int m, int n,
              int i, int j, int prev, int flag) {
    int v = h[i][j];
    if ((v < prev) || (a[i][j] & flag)) return;
    a[i][j] |= flag;
    if (i > 0) travel(h, a, m, n, i - 1, j, v, flag);
    if (j > 0) travel(h, a, m, n, i, j - 1, v, flag);
    if (j < n - 1) travel(h, a, m, n, i, j + 1, v, flag);
    if (i < m - 1) travel(h, a, m, n, i + 1, j, v, flag);
  }
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      travel(heights, a, m, n, i, 0, -1, Pacific);
      travel(heights, a, m, n, i, n - 1, -1, Atlantic);
    }
    for (int j = 0; j < n; ++j) {
      travel(heights, a, m, n, 0, j, -1, Pacific);
      travel(heights, a, m, n, m - 1, j, -1, Atlantic);
    }
    vector<vector<int>> r;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == PacificAtlantic) r.push_back({i, j});
      }
    }
    return r;
  }
};
