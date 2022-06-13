#include <vector>
using namespace std;

class Solution {
 public:
  int maxRotateFunction(vector<int> &nums) {
    int s = 0, x = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      s += nums[i];
      x += i * nums[i];
    }
    int m = x;
    for (int i = 0; i < n - 1; i++) {
      x -= s - nums[i] * n;
      if (x > m) m = x;
    }
    return m;
  }
};
