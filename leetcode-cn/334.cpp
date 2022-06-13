#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
      return false;
    }
    int last = nums[0], last2 = INT_MAX;
    ;
    for (int i = 1; i < n; i++) {
      if (nums[i] > last2) {
        return true;
      } else if (nums[i] > last && nums[i] < last2) {
        last2 = nums[i];
      } else if (nums[i] < last) {
        last = nums[i];
      }
    }
    return false;
  }
};
