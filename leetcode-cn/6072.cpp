#include <vector>
using namespace std;

struct N {
  int n0;
  int n2;
  int n5;
  N() : n0(0), n2(0), n5(0) {}
  N operator+=(const N &o) {
    n0 += o.n0;
    n2 += o.n2;
    n5 += o.n5;
    return *this;
  }
  N operator-=(const N &o) {
    n0 -= o.n0;
    n2 -= o.n2;
    n5 -= o.n5;
    return *this;
  }
};

struct NN {
  N self;
  N left;
  N right;
};

class Solution {
 public:
  int maxTrailingZeros(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<NN>> g(m, vector<NN>(n));
    N r[m], c[n];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        NN &d = g[i][j];
        genN(grid[i][j], d.self);
        r[i] += d.self;
        c[j] += d.self;
      }
    }
    for (int i = 0; i < m; ++i) {
      N left, right = r[i];
      for (int j = 0; j < n; ++j) {
        NN &d = g[i][j];
        if (j > 0) left += g[i][j - 1].self;
        right -= d.self;
        d.left = left;
        d.right = right;
      }
    }
    int res = 0;
    for (int j = 0; j < n; ++j) {
      N up, down = c[j];
      for (int i = 0; i < m; ++i) {
        NN &d = g[i][j];
        if (i > 0) up += g[i - 1][j].self;
        down -= d.self;
        res = max(res, calc(up, d.left, d.self));
        res = max(res, calc(up, d.right, d.self));
        res = max(res, calc(down, d.left, d.self));
        res = max(res, calc(down, d.right, d.self));
      }
    }
    return res;
  }

  void genN(int k, N &n) {
    if (k % 10 == 0) {
      while (k && k % 10 == 0) {
        ++n.n0;
        k /= 10;
      }
    }
    if (k && k % 5 == 0) {
      while (k % 5 == 0) {
        ++n.n5;
        k /= 5;
      }
    }
    if (k % 2 == 0) {
      while (k && (k & 1) == 0) {
        ++n.n2;
        k = k >> 1;
      }
    }
  }

  int calc(const N &a, const N &b, const N &c) {
    return a.n0 + b.n0 + c.n0 + min(a.n2 + b.n2 + c.n2, a.n5 + b.n5 + c.n5);
  }
};
