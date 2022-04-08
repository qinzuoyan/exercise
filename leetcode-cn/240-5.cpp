#include <vector>
using namespace std;

class Solution {
 public:
  // O(m+n) : 64ms
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
