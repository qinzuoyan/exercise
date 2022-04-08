#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(n*s)
  bool canPartition(vector<int>& nums) {
    int n = nums.size(), s = 0;
    for (int num : nums) {
      s += num;
    }
    if (s % 2 != 0) return false;
    s /= 2;
    int a[n * s];  // a[n][s]
    memset(a, -1, sizeof(int) * n * s);
    return canPartition(nums, a, s, n - 1, s);
  }

  bool canPartition(vector<int>& nums, int* a, int s, int pos, int sum) {
    int i = s * pos + sum - 1;
    if (a[i] != -1) {
      return a[i];
    }
    if (nums[pos] == sum) {
      a[i] = 1;
      return true;
    }
    if (pos > 0 && canPartition(nums, a, s, pos - 1, sum)) {
      a[i] = 1;
      return true;
    }
    if (pos > 0 && nums[pos] < sum &&
        canPartition(nums, a, s, pos - 1, sum - nums[pos])) {
      a[i] = 1;
      return true;
    }
    a[i] = 0;
    return false;
  }
};
