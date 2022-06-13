#include <vector>
using namespace std;

class Solution {
 public:
  void subsets(vector<vector<int>> &r, vector<int> &nums, size_t i,
               vector<int> &t) {
    if (i == nums.size() - 1) {
      r.push_back(t);
      t.push_back(nums[i]);
      r.push_back(t);
      t.pop_back();
    } else {
      subsets(r, nums, i + 1, t);
      t.push_back(nums[i]);
      subsets(r, nums, i + 1, t);
      t.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> r;
    vector<int> t;
    subsets(r, nums, 0, t);
    return r;
  }
};
