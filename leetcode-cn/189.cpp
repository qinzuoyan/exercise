#include <vector>
using namespace std;

class Solution {
 public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) {
      return;
    }
    int s = 0, c = n;
    while (c) {
      int t = nums[s], i = s;
      while (true) {
        // nums[i] <= nums[j]
        int j = (i + n - k) % n;
        c--;
        if (j == s) {
          nums[i] = t;
          break;
        }
        nums[i] = nums[j];
        i = j;
      }
      s++;
    }
  }
};
