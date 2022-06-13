#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    size_t n = nums.size();
    int c = INT_MAX, r;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      size_t j = i + 1;
      size_t k = n - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < target) {
          j++;
          while (j < k && nums[j] == nums[j - 1]) j++;
        } else if (sum > target) {
          k--;
          while (j < k && nums[k] == nums[k + 1]) k--;
        } else {
          return target;
        }
        int d = sum > target ? sum - target : target - sum;
        if (d < c) {
          c = d;
          r = sum;
        }
      }
    }
    return r;
  }
};
