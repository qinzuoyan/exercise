#include <cassert>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class NumTree {
  struct Node {
    int min_weight;
    Node() : min_weight(1) {}
  };

 public:
  NumTree(int n) : _n(n) { _a = new Node[_n * 4]; }

  ~NumTree() { delete[] _a; }

  // find the first index >= i with weight <= w
  // return -1 mean not found
  int find(int i, int w) { return find(0, _n - 1, 1, i, w); }

  // update index i's weight to w
  void update(int i, int w) { update(0, _n - 1, 1, i, w); }

 private:
  int find(int l, int r, int pos, int i, int w) {
    if (_a[pos].min_weight > w) {
      return -1;
    }
    if (l == r) {
      return l;
    }
    int m = (l + r) / 2;
    if (i <= m && _a[pos << 1].min_weight <= w) {
      int r = find(l, m, pos << 1, i, w);
      if (r != -1) {
        return r;
      }
    }
    if (_a[pos << 1 | 1].min_weight <= w) {
      return find(m + 1, r, pos << 1 | 1, i, w);
    }
    return -1;
  }

  int update(int l, int r, int pos, int i, int w) {
    if (l == r) {
      assert(l == i);
      _a[pos].min_weight = w;
      return w;
    }
    int m = (l + r) / 2;
    if (i <= m) {
      _a[pos].min_weight =
          min(update(l, m, pos << 1, i, w), _a[pos << 1 | 1].min_weight);
    } else {
      _a[pos].min_weight =
          min(_a[pos << 1].min_weight, update(m + 1, r, pos << 1 | 1, i, w));
    }
    return _a[pos].min_weight;
  }

  Node* _a;
  int _n;
};

class Solution {
 public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    NumTree tr(k);
    int n = arrival.size(), max = 0;
    vector<int> a(k), b(k, 1);
    for (int j = 0; j < n; j++) {
      int t = arrival[j], l = load[j], i = j % k, p = -1;
      if (((p = tr.find(i, t)) != -1) || (i > 0 && (p = tr.find(0, t)) != -1)) {
        a[p]++;
        b[p] = t + l;
        tr.update(p, b[p]);
        if (a[p] > max) {
          max = a[p];
        }
      }
    }
    vector<int> r;
    for (int j = 0; j < k; j++) {
      if (a[j] == max) {
        r.push_back(j);
      }
    }
    return r;
  }
};
