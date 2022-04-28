#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      int *i = &nums[0], *j = i + nums.size() - 1;
      while (i < j) {
        while (i < j && (*i & 1) == 0) ++i;
        while (i < j && (*j & 1) == 1) --j;
        if (i < j) {
          int t = *i;
          *i++ = *j;
          *j-- = t;
        }
      }
      return nums;
    }
};
