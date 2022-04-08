#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(nlog(n))
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};
