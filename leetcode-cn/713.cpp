#include <vector>
using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k == 0) return 0;
    int n = nums.size(), i = 0, j = 0, m = 1, r = 0;
    while (j < n) {
      m *= nums[j];
      while (m >= k) m /= nums[i++];
      if (i <= j) r += j - i + 1;
      ++j;
    }
    return r;
  }
};
