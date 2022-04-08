#include <climits>
#include <cstring>
#include <functional>
#include <vector>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int a[m * n];
    memset(a, -1, sizeof(int) * m * n);
    a[0] = grid[0][0];
    return minPathSum(grid, a, n, m - 1, n - 1);
  }
  int minPathSum(vector<vector<int>>& g, int* a, int n, int i, int j) {
    int p = i * n + j;
    if (a[p] >= 0) return a[p];
    int s = INT_MAX;
    if (i > 0) s = min(s, minPathSum(g, a, n, i - 1, j));
    if (j > 0) s = min(s, minPathSum(g, a, n, i, j - 1));
    a[p] = s + g[i][j];
    return a[p];
  }
};
