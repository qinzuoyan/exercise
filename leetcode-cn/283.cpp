#include <vector>
using namespace std;

class Solution {
 public:
  void swap(vector<int>& a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  void moveZeroes(vector<int>& nums) {
    int i = -1, j = 0, n = nums.size();
    while (j < n) {
      if (nums[j] == 0) {
        if (i < 0) {
          i = j;
        }
      } else {  // a[j] != 9
        if (i >= 0) {
          swap(nums, i, j);
          i++;
        }
      }
      j++;
    }
  }
};
