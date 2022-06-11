#include <cassert>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  void update_self(vector<vector<int>> &a, int n, int m, int i, int j,
                   stack<pair<int, int>> &s1, stack<pair<int, int>> &s2) {
    if (a[i][j] == -1) return;
    int c = 0;
    if (i > 0 && a[i - 1][j] != -1) c++;
    if (i < n - 1 && a[i + 1][j] != -1) c++;
    if (j > 0 && a[i][j - 1] != -1) c++;
    if (j < m - 1 && a[i][j + 1] != -1) c++;
    a[i][j] = c;
    if (c == 1)
      s1.emplace(i, j);
    else if (c == 2)
      s2.emplace(i, j);
  }

  void update_neighbor(vector<vector<int>> &a, int n, int m, int i, int j,
                       stack<pair<int, int>> &s1, stack<pair<int, int>> &s2) {
    if (i > 0 && a[i - 1][j] != -1) {
      --a[i - 1][j];
      if (a[i - 1][j] == 1)
        s1.emplace(i - 1, j);
      else if (a[i - 1][j] == 2)
        s2.emplace(i - 1, j);
    }
    if (i < n - 1 && a[i + 1][j] != -1) {
      --a[i + 1][j];
      if (a[i + 1][j] == 1)
        s1.emplace(i + 1, j);
      else if (a[i + 1][j] == 2)
        s2.emplace(i + 1, j);
    }
    if (j > 0 && a[i][j - 1] != -1) {
      --a[i][j - 1];
      if (a[i][j - 1] == 1)
        s1.emplace(i, j - 1);
      else if (a[i][j - 1] == 2)
        s2.emplace(i, j - 1);
    }
    if (j < m - 1 && a[i][j + 1] != -1) {
      --a[i][j + 1];
      if (a[i][j + 1] == 1)
        s1.emplace(i, j + 1);
      else if (a[i][j + 1] == 2)
        s2.emplace(i, j + 1);
    }
  }

  int domino(int n, int m, vector<vector<int>> &broken) {
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &v : broken) {
      a[v[0]][v[1]] = -1;
    }
    stack<pair<int, int>> s1, s2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        update_self(a, n, m, i, j, s1, s2);
      }
    }
    int i, j, x, y, r = 0;
    while (s1.size() || s2.size()) {
      if (s1.size()) {
        i = s1.top().first;
        j = s1.top().second;
        s1.pop();
      } else {
        i = s2.top().first;
        j = s2.top().second;
        s2.pop();
      }
      if (a[i][j] < 1) continue;
      if (i > 0 && a[i - 1][j] != -1)
        x = i - 1, y = j;
      else if (i < n - 1 && a[i + 1][j] != -1)
        x = i + 1, y = j;
      else if (j > 0 && a[i][j - 1] != -1)
        x = i, y = j - 1;
      else if (j < m - 1 && a[i][j + 1] != -1)
        x = i, y = j + 1;
      else
        assert(false);
      bool updata_i_j = (a[i][j] >= 2);
      bool updata_x_y = (a[x][y] >= 2);
      a[i][j] = -1;
      a[x][y] = -1;
      if (updata_i_j) update_neighbor(a, n, m, i, j, s1, s2);
      if (updata_x_y) update_neighbor(a, n, m, x, y, s1, s2);
      r++;
    }
    return r;
  }
};
