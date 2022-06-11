#include <vector>
using namespace std;

class Solution {
 public:
  long long subArrayRanges(vector<int> &nums) {
    size_t n = nums.size();
    long long r = 0;
    for (size_t i = 0; i < n - 1; i++) {
      int min = nums[i];
      int max = min;
      for (size_t j = i + 1; j < n; j++) {
        int t = nums[j];
        if (t < min) min = t;
        if (t > max) max = t;
        r += max - min;
      }
    }
    return r;
  }
};
