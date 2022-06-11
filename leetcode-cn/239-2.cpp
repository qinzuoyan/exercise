#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(nlog(n))
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> q;
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      q.emplace(nums[i], i);
    }
    vector<int> r = {q.top().first};
    for (int j = k; j < n; j++) {
      q.emplace(nums[j], j);
      while (q.top().second <= j - k) {
        q.pop();
      }
      r.push_back(q.top().first);
    }
    return r;
  }
};
