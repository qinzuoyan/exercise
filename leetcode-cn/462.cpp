#include <climits>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  long long check(vector<int> &nums, int k) {
    long long s = 0;
    for (int i : nums) s += abs(k - i);
    return s;
  }
  int minMoves2(vector<int> &nums) {
    int n = nums.size(), x = INT_MAX, y = INT_MIN;
    for (int i : nums) {
      if (i < x) x = i;
      if (i > y) y = i;
    }
    while (x < y) {
      int m = (x + y) >> 1;
      long long mv = check(nums, m), rv = check(nums, m + 1);
      if (mv == rv)
        x = m, y = m;
      else if (mv < rv)
        y = m;
      else
        x = m + 1;
    }
    int r = 0;
    for (int i : nums) r += abs(x - i);
    return r;
  }
};
