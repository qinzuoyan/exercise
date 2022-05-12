#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int n = strs.size(), m = strs[0].size(), r = 0;
    if (n == 1) return r;
    for (int j = 0; j < m; ++j) {
      for (int i = 1; i < n; ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          ++r;
          break;
        }
      }
    }
    return r;
  }
};

