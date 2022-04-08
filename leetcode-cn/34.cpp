#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> r({-1, -1});
    for (size_t i = 0; i < nums.size() && nums[i] <= target; i++) {
      if (nums[i] == target) {
        if (r[0] == -1) r[0] = i;
        r[1] = i;
      }
    }
    return r;
  }
};
