#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(n)
  int maxSubArray(vector<int> &nums) {
    int max = INT_MIN, c = 0;
    for (int i : nums) {
      c += i;
      if (c > max) max = c;
      if (c <= 0) c = 0;
    }
    return max;
  }
};
