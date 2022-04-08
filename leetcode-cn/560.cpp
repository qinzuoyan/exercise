#include <vector>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int c = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      int s = 0;
      for (size_t j = i; j < nums.size(); j++) {
        s += nums[j];
        if (s == k) c++;
      }
    }
    return c;
  }
};
