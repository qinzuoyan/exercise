#include <vector>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
      return false;
    }
    int i = 0, j = m - 1;
    while (i < j) {
      int mid = (i + j + 1) >> 1;
      int d = target - matrix[mid][0];
      if (d == 0) {
        return true;
      } else if (d > 0) {
        i = mid;
      } else {
        j = mid - 1;
      }
    }
    int row = i;
    i = 0, j = n - 1;
    while (i < j) {
      int mid = (i + j) >> 1;
      int d = target - matrix[row][mid];
      if (d == 0) {
        return true;
      } else if (d > 0) {
        i = mid + 1;
      } else {
        j = mid - 1;
      }
    }
    return i == j && matrix[row][i] == target;
  }
};
