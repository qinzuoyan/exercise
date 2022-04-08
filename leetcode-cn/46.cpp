#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> r;
    permute(r, nums, 0);
    return r;
  }

  void swap(vector<int>& nums, size_t x, size_t y) {
    int t = nums[x];
    nums[x] = nums[y];
    nums[y] = t;
  }

  void permute(vector<vector<int>>& r, vector<int>& nums, size_t k) {
    if (k == nums.size()) {
      r.push_back(nums);
      return;
    }
    for (size_t i = k; i < nums.size(); i++) {
      swap(nums, k, i);
      permute(r, nums, k + 1);
      swap(nums, k, i);
    }
  }
};
