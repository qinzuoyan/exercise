#include <climits>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  pair<int, int> sumAndInsert(int *a, int l, int r, int i, int n) {
    if (n < l) {
      return pair<int, int>(a[i], 0);
    }
    if (r < n) {
      return pair<int, int>(a[i], a[i]);
    }
    if (l == r) {
      return pair<int, int>(++a[i], 0);
    }
    int m = (l + r) >> 1;
    auto pr1 = sumAndInsert(a, l, m, i << 1, n);
    auto pr2 = sumAndInsert(a, m + 1, r, i << 1 | 1, n);
    a[i] = pr1.first + pr2.first;
    return pair<int, int>(a[i], pr1.second + pr2.second);
  }

  vector<int> countSmaller(vector<int> &nums) {
    int min_num = INT_MAX, max_num = INT_MIN;
    for (int i : nums) {
      min_num = min(min_num, i);
      max_num = max(max_num, i);
    }
    int n = max_num - min_num + 1, len = nums.size();
    int a[n * 4];
    memset(a, 0, sizeof(a));
    vector<int> r(len);
    for (int i = len - 1; i >= 0; i--) {
      r[i] = sumAndInsert(a, min_num, max_num, 1, nums[i]).second;
    }
    return r;
  }
};
