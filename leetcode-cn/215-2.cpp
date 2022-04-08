#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(nlog(k))
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i : nums) {
      if (q.size() < (size_t)k || i > q.top()) q.push(i);
      if (q.size() > (size_t)k) q.pop();
    }
    return q.top();
  }
};
