#include <vector>
using namespace std;

class Solution {
 public:
  void swap(vector<int>& nums, int x, int y) {
    int t = nums[x];
    nums[x] = nums[y];
    nums[y] = t;
  }
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i >= 0) {
      int j = i + 1, k = nums[i];
      while (j < n && nums[j] > k) j++;
      swap(nums, i, j - 1);
    }
    int x = i + 1, y = n - 1;
    while (x < y) swap(nums, x++, y--);
  }
};
