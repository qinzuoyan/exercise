#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(n)
  int trap(vector<int>& height) {
    int n = height.size(), sum = 0;
    stack<int> s;
    for (int i = 0; i < n; i++) {
      int h = height[i];
      while (!s.empty() && h > height[s.top()]) {
        int left = height[s.top()];
        s.pop();
        if (!s.empty()) {
          sum += (min(height[s.top()], h) - left) * (i - s.top() - 1);
        }
      }
      s.push(i);
    }
    return sum;
  }
};
