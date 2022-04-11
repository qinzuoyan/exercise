#include <vector>
using namespace std;

class Solution {
 public:
  int domino(int n, int m, vector<vector<int>>& broken) {
    int a[n][m];
    memset(a, 0, sizeof(a));
    for (auto& v : broken) {
      a[v[0]][v[1]] = -1;
    }
    deque<pair<int, int>> v1, v2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j]) continue;
        if (i > 0 && a[i - 1][j] != -1) a[i][j]++;
        if (i < n - 1 && a[i + 1][j] != -1) a[i][j]++;
        if (j > 0 && a[i][j - 1] != -1) a[i][j]++;
        if (j < m - 1 && a[i][j + 1] != -1) a[i][j]++;
        if (a[i][j] == 1)
          v1.emplace_back(i, j);
        else if (a[i][j] == 2)
          v2.emplace_back(i, j);
      }
    }
    while (v1.size() || v2.size()) {
      if (v1.size()) {
        int i = v1.front().first;
        int j = v1.front().second;
        int x = 0, y = 0;
        v1.pop_front();
        if (i > 0 && a[i - 1][j] != -1) x = i - 1, y = j;
        else if (i < n - 1 && a[i + 1][j] != -1) x = i + 1, y = j;
        else if (j > 0 && a[i][j - 1] != -1) x = i, y = j - 1;
        else if (j < m - 1 && a[i][j + 1] != -1) x = i, y = j + 1;
        else assert(false);
        a[i][j] = -1;
        a[x][y] = -1;
        i = x, j = y;
        if (i > 0 && a[i - 1][j] != -1) a[i][j]--;
        if (i < n - 1 && a[i + 1][j] != -1) a[i][j]--;
        if (j > 0 && a[i][j - 1] != -1) a[i][j]++;
        if (j < m - 1 && a[i][j + 1] != -1) a[i][j]++;
      }
      else {
      }
    }
    return 0;
  }
};
