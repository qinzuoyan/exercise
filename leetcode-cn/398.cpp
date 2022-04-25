#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
 public:
  Solution(vector<int>& nums) {
    int n = nums.size();
    v.resize(n);
    for (int i = 0; i < n; i++) {
      v[i] = pair<int, int>(nums[i], i);
    }
    sort(v.begin(), v.end());
    srand(time(NULL));
  }

  int pick(int target) {
    pair<int, int> pr1(target, 0), pr2(target + 1, 0);
    auto it1 = lower_bound(v.begin(), v.end(), pr1);
    auto it2 = lower_bound(v.begin(), v.end(), pr2);
    int len = it2 - it1;
    if (len == 1) {
      return it1->second;
    } else {
      int i = rand() % len;
      return (it1 + i)->second;
    }
  }

  vector<pair<int, int>> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
