#include <vector>
using namespace std;

class Solution {
 public:
  // O(min(mlog(n),nlog(m))) : 96ms
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    bool by_row = (n >= m);
    int s = (by_row ? m : n);
    int j = (by_row ? n - 1 : m - 1);
    for (int k = 0; k < s; k++) {
      int i = 0;
      if (target < (by_row ? matrix[k][i] : matrix[i][k]) ||
          target > (by_row ? matrix[k][j] : matrix[j][k])) {
        continue;
      }
      while (i <= j) {
        int mid = (i + j) >> 1;
        int d = target - (by_row ? matrix[k][mid] : matrix[mid][k]);
        if (d == 0) {
          return true;
        } else if (d > 0) {
          i = mid + 1;
        } else {
          j = mid - 1;
        }
      }
    }
    return false;
  }
};
