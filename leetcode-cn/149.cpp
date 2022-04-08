#include <map>
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
  int merge(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return x;
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
  int set_size(int x) { return -_v[find(x)]; }

 private:
  std::vector<int> _v;
};

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 1) {
      return 1;
    }
    map<pair<pair<int, int>, pair<int, double>>, int> m;
    UnionFindSet u;
    pair<pair<int, int>, pair<int, double>> x, y;  // pair<point, direction>
    for (int i = 0; i < n - 1; i++) {
      x.first.first = points[i][0];
      x.first.second = points[i][1];
      for (int j = i + 1; j < n; j++) {
        y.first.first = points[j][0];
        y.first.second = points[j][1];
        int dx = points[i][0] - points[j][0];
        double dy = points[i][1] - points[j][1];
        dy = (dx == 0 ? 1 : dy / dx);
        dx = (dx == 0 ? 0 : 1);
        x.second.first = y.second.first = dx;
        x.second.second = y.second.second = dy;
        int idx, idy;
        auto pr = m.find(x);
        if (pr == m.end()) {
          idx = u.new_item();
          m[x] = idx;
        } else {
          idx = pr->second;
        }
        pr = m.find(y);
        if (pr == m.end()) {
          idy = u.new_item();
          m[y] = idy;
        } else {
          idy = pr->second;
        }
        u.merge(idx, idy);
      }
    }
    int z = u.item_count(), r = 0;
    for (int i = 1; i <= z; i++) {
      int k = u.set_size(i);
      if (k > r) {
        r = k;
      }
    }
    return r;
  }
};
