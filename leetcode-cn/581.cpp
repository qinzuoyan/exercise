#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(nlog(n))
  int findUnsortedSubarray(vector<int>& nums) {
    vector<int> v = nums;
    sort(v.begin(), v.end());
    int i = 0, n = nums.size();
    while (i < n && nums[i] == v[i]) i++;
    if (i == n) return 0;
    int j = n - 1;
    while (nums[j] == v[j]) j--;
    return j - i + 1;
  }
};
