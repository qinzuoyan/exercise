#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(n)
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> r;
    deque<int> q;
    int n = nums.size();
    r.reserve(n);
    for (int i = 0; i < n; i++) {
      while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
      q.push_back(i);
      if (q.front() <= i - k) q.pop_front();
      if (i >= k - 1) r.push_back(nums[q.front()]);
    }
    return r;
  }
};
