#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> m;
    int n = nums.size() / 2;
    for (int i : nums)
      if (++m[i] > n) return i;
    return 0;
  }
};
