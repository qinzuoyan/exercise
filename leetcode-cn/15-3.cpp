#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int a[3];
    vector<vector<int>> r;
    size_t n = nums.size();
    if (n < 3) return r;

    sort(nums.begin(), nums.end());
    if (nums[0] > 0 || nums[n - 1] < 0) return r;

    size_t start = 0;
    size_t end = n - 1;
    int sum = 0;

    // sweep left nums
    sum = nums[end] + nums[end - 1];
    while (start < end && sum + nums[start] < 0) start++;
    if (end - start < 2) return r;

    // swap rigth nums
    sum = nums[start] + nums[start + 1];
    while (start < end && sum + nums[end] > 0) end--;
    if (end - start < 2) return r;

    for (size_t i = start; i <= end && nums[i] <= 0; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      size_t j = i + 1;

      // sweep rigth nums
      sum = nums[i] + nums[j];
      while (j < end && sum + nums[end] > 0) end--;
      if (end - i < 2) return r;

      size_t k = end;
      while (j < k) {
        sum = nums[i] + nums[j] + nums[k];
        if (sum < 0) {
          j++;
        } else if (sum > 0) {
          k--;
        } else {
          a[0] = nums[i];
          a[1] = nums[j];
          a[2] = nums[k];
          r.emplace_back(a, a + 3);
          while (j < k && nums[j] == nums[j + 1]) j++;
          while (j < k && nums[k - 1] == nums[k]) k--;
          j++;
          k--;
        }
      }
    }
    return r;
  }
};
