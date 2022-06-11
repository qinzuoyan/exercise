#include <vector>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int len = height.size();
    int i = 0, j = len - 1, m = 0;
    while (i < j) {
      int x = height[i], y = height[j];
      int w = min(x, y) * (j - i);
      if (w > m) m = w;
      if (x <= y)
        while (++i < j && height[i] <= x)
          ;
      if (x >= y)
        while (i < --j && height[j] <= y)
          ;
    }
    return m;
  }
};
