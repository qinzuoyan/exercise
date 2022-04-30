#include <vector>
using namespace std;

class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    int min = 10001, max = -1;
    for (int i : nums) {
      if (i < min) min = i;
      if (i > max) max = i;
    }
    int r = max - min - k - k;
    return r < 0 ? 0 : r;
  }
};
