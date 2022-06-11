#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  pair<int, int> searchRange(vector<int> &nums, int start, int end,
                             int target) {
    if (nums[start] > target || nums[end] < target) return make_pair(-1, -1);
    if (nums[start] == target && nums[end] == target)
      return make_pair(start, end);
    int mid = (start + end) / 2;
    pair<int, int> left = searchRange(nums, start, mid, target);
    pair<int, int> right = searchRange(nums, mid + 1, end, target);
    if (left.first == -1)
      return right;
    else if (right.first == -1)
      return left;
    else
      return make_pair(left.first, right.second);
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> r({-1, -1});
    if (nums.empty()) return r;
    pair<int, int> ret = searchRange(nums, 0, nums.size() - 1, target);
    r[0] = ret.first;
    r[1] = ret.second;
    return r;
  }
};
