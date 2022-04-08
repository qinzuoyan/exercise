#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> r;
    int n = nums.size();
    for (int num : nums) {
      nums[(num - 1) % n] += n;
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] <= n) {
        r.push_back(i + 1);
      }
    }
    return r;
  }
};
