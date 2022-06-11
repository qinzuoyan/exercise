#include <vector>
using namespace std;

class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      int d = target - matrix[i][j];
      if (d == 0) {
        return true;
      } else if (d > 0) {
        i++;
      } else {
        j--;
      }
    }
    return false;
  }
};
