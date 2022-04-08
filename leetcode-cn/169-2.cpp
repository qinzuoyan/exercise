#include <vector>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int c = 0, r = 0;
    for (int i : nums) {
      if (c == 0) r = i;
      c += (r == i ? 1 : -1);
    }
    return r;
  }
};
