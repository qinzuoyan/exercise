#include <vector>
using namespace std;

class UnionFindSet {
 public:
  UnionFindSet(int initItemCount = 0) : _v(initItemCount + 1) {
    for (int i = 1; i <= initItemCount; ++i) {
      _v[i] = -1;
    }
  }
  int find(int x) { return _v[x] < 0 ? x : (_v[x] = find(_v[x])); }
  int merge(int i, int j) {
    int x = find(i), y = find(j);
    if (x == y) return x;
    if (_v[x] < _v[y]) {
      // merge y to x
      _v[x] += _v[y];
      _v[y] = x;
      return x;
    } else {
      // merge x to y
      _v[y] += _v[x];
      _v[x] = y;
      return y;
    }
  }
  int new_item() {
    _v.emplace_back(-1);
    return _v.size() - 1;
  }
  int item_count() { return _v.size() - 1; }
  int diff_set_count() {
    int r = 0, n = _v.size();
    for (int i = 1; i < n; ++i) {
      if (_v[i] < 0) {
        r++;
      }
    }
    return r;
  }

 private:
  std::vector<int> _v;
};

class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    UnionFindSet a;
    vector<vector<int>> v(m);
    for (int i = 0; i < m; i++) {
      v[i].resize(n);
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          int id1 = 0, id2 = 0;
          if (i && v[i - 1][j]) id1 = v[i - 1][j];
          if (j && v[i][j - 1]) id2 = v[i][j - 1];
          if (!id1 && !id2) {
            v[i][j] = a.new_item();
          } else if (id1 && !id2) {
            v[i][j] = id1;
          } else if (!id1 && id2) {
            v[i][j] = id2;
          } else {  // id1 && id2
            v[i][j] = a.merge(id1, id2);
          }
        }
      }
    }
    return a.diff_set_count();
  }
};
