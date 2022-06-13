#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int> &nums) {
    int n = nums.size();
    vector<int> r;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == i + 1) continue;
      int k = nums[i];
      nums[i] = 0;
      while (nums[k - 1] > 0 && nums[k - 1] != k) {
        int t = nums[k - 1];
        nums[k - 1] = k;
        k = t;
      }
      if (nums[k - 1] == 0)
        nums[k - 1] = k;
      else
        r.push_back(k);
    }
    return r;
  }
};
