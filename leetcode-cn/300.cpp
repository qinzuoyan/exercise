#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    int a[n], r = 1;
    a[0] = 1;
    for (int i = 1; i < n; i++) {
      int m = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i] && a[j] + 1 > m) {
          m = a[j] + 1;
        }
      }
      a[i] = m;
      if (m > r) {
        r = m;
      }
    }
    return r;
  }
};
