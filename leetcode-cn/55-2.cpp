#include <vector>
using namespace std;

class Solution {
 public:
  // O(n)
  bool canJump(vector<int>& nums) {
    int n = nums.size(), m = 0;
    for (int i = 0; i < n - 1 && m >= i && m < n - 1; ++i) {
      m = max(i + nums[i], m);
    }
    return m >= n - 1;
  }
};
