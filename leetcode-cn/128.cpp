#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(nlog(n))
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int max = 1, last = nums[0], begin = nums[0], n = nums.size();
    for (int i = 1; i < n; i++) {
      if (nums[i] == last) {
        continue;
      } else if (nums[i] == last + 1) {
        last = nums[i];
      } else {
        if (last - begin + 1 > max) max = last - begin + 1;
        last = nums[i];
        begin = nums[i];
      }
    }
    if (last - begin + 1 > max) max = last - begin + 1;
    return max;
  }
};
