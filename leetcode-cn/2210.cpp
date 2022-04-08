#include <vector>
using namespace std;

class Solution {
 public:
  int countHillValley(vector<int>& nums) {
    int k = nums[1] - nums[0], n = 0;
    for (size_t i = 2; i < nums.size(); i++) {
      int t = nums[i] - nums[i - 1];
      if (t != 0) {
        if (t * k < 0) n++;
        k = t;
      }
    }
    return n;
  }
};
