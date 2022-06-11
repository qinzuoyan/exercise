#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(n)
  int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size();
    int i = 0, k = 1;
    while (k < n && nums[k - 1] <= nums[k]) k++;
    if (k == n) return 0;
    i = k;
    while (k < n) {
      while (i > 0 && nums[i - 1] > nums[k]) i--;
      k++;
    }
    int j = n - 1;
    k = n - 2;
    while (k >= 0 && nums[k + 1] >= nums[k]) k--;
    j = k;
    while (k >= 0) {
      while (j < n - 1 && nums[j + 1] < nums[k]) j++;
      k--;
    }
    return j - i + 1;
  }
};
