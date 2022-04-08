#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int pos, int target, int* a,
                        int max) {
    if (pos < 0) return target == 0 ? 1 : 0;
    int i = pos * max * 2 + target + max;
    if (a[i] != -1) return a[i];
    a[i] = findTargetSumWays(nums, pos - 1, target + nums[pos], a, max) +
           findTargetSumWays(nums, pos - 1, target - nums[pos], a, max);
    return a[i];
  }

  int findTargetSumWays(vector<int>& nums, int target) {
    if (target < 0) target = -target;
    int sum = 0;
    for (int n : nums) sum += n;
    int max = sum + target + 1;
    int len = nums.size() * max * 2;
    int a[len];
    memset(a, -1, sizeof(int) * len);
    return findTargetSumWays(nums, nums.size() - 1, target, a, max);
  }
};
