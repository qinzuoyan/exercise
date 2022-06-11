#include <vector>
using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return 0;
    int i = 0, j = n - 1;
    while (i + 1 < j) {
      int m = (i + j) >> 1;
      if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
        return m;
      }
      if (nums[m - 1] > nums[m]) {
        j = m;
      } else {
        i = m;
      }
    }
    return nums[i] >= nums[j] ? i : j;
  }
};
