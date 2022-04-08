#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(nlog(n))
  int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); i += 2) {
      if (nums[i] != nums[i - 1]) return nums[i - 1];
    }
    return 0;
  }
};
