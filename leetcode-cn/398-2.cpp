#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Solution {
 public:
  Solution(vector<int> &nums) {
    int n = nums.size();
    v.resize(n);
    for (int i = 0; i < n; i++) {
      v[i] = pair<int, int>(nums[i], i);
    }
    sort(v.begin(), v.end());
    int p = 0;
    v[p].second = -v[p].second - 30000;
    for (int i = 1; i < n; i++) {
      if (v[i].first == v[p].first) {
        v[p].second -= 30000;
      } else {
        p = i;
        v[p].second = -v[p].second - 30000;
      }
    }
    srand(time(NULL));
  }

  int pick(int target) {
    pair<int, int> pr(target, INT_MIN);
    auto it = lower_bound(v.begin(), v.end(), pr);
    int len = (-it->second) / 30000;
    if (len == 1) {
      return (-it->second) % 30000;
    } else {
      int i = rand() % len;
      return i == 0 ? (-it->second) % 30000 : (it + i)->second;
    }
  }

  vector<pair<int, int>> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
