#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(n)
  int singleNumber(vector<int>& nums) {
    int r = 0;
    for (int n : nums) r ^= n;
    return r;
  }
};
