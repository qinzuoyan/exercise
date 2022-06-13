#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> a(heights);
    sort(a.begin(), a.end());
    int r = 0, n = a.size();
    for (int i = 0; i < n; ++i) {
      if (a[i] != heights[i]) ++r;
    }
    return r;
  }
};
