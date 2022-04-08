#include <climits>
#include <cstring>
#include <vector>
using namespace std;

class BinaryIndexTree {
 public:
  // [1, n]
  BinaryIndexTree(int n) : _n(n) {
    _v = new int[_n + 1];
    memset(_v, 0, sizeof(int) * (_n + 1));
  }

  ~BinaryIndexTree() { delete[] _v; }

  // 1 <= i <= n
  void update(int i, int x) {
    for (int p = i; p <= _n; p += lowbit(p)) {
      _v[p] += x;
    }
  }

  // 0 <= i <= n
  int query(int i) {
    int r = 0;
    for (int p = i; p; p -= lowbit(p)) {
      r += _v[p];
    }
    return r;
  }

  // 1 <= i <= j <= n
  int query(int i, int j) { return query(j) - query(i - 1); }

 private:
  int lowbit(int i) { return i & (-i); }

  int _n;
  int* _v;
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int min_num = INT_MAX, max_num = INT_MIN;
    for (int i : nums) {
      min_num = min(min_num, i);
      max_num = max(max_num, i);
    }
    int n = max_num - min_num + 1, len = nums.size();
    BinaryIndexTree tr(n);
    vector<int> r(len);
    for (int i = len - 1; i >= 0; i--) {
      int idx = nums[i] - min_num + 1;
      r[i] = tr.query(idx - 1);
      tr.update(idx, 1);
    }
    return r;
  }
};
