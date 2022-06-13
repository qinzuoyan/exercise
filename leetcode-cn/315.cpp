#include <climits>
#include <cstring>
#include <vector>
using namespace std;

class NumArray {
 private:
  int _n;
  int *_v;

  int insert(int l, int r, int i, int index) {
    if (index < l || r < index) {
      return _v[i];
    }
    if (l == r) {
      return ++_v[i];
    }
    int mid = (l + r) >> 1;
    return (_v[i] = insert(l, mid, i << 1, index) +
                    insert(mid + 1, r, i << 1 | 1, index));
  }

  int sumRange(int l, int r, int i, int left, int right) {
    if (right < l || r < left) {
      return 0;
    }
    if (left <= l && r <= right) {
      return _v[i];
    }
    int mid = (l + r) >> 1;
    return sumRange(l, mid, i << 1, left, right) +
           sumRange(mid + 1, r, i << 1 | 1, left, right);
  }

 public:
  // [0, n-1]
  NumArray(int n) : _n(n) {
    _v = new int[_n * 4];
    memset(_v, 0, sizeof(int) * _n * 4);
  }

  ~NumArray() { delete[] _v; }

  void insert(int index) { insert(0, _n - 1, 1, index); }

  int sumRange(int left, int right) {
    return sumRange(0, _n - 1, 1, left, right);
  }
};

class Solution {
 public:
  vector<int> countSmaller(vector<int> &nums) {
    int min_num = INT_MAX, max_num = INT_MIN;
    for (int i : nums) {
      min_num = min(min_num, i);
      max_num = max(max_num, i);
    }
    int n = max_num - min_num + 1, len = nums.size();
    NumArray a(n);
    vector<int> r(len);
    for (int i = len - 1; i >= 0; i--) {
      r[i] = (nums[i] == min_num ? 0 : a.sumRange(0, nums[i] - min_num - 1));
      a.insert(nums[i] - min_num);
    }
    return r;
  }
};
