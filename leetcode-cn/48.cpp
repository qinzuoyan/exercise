#include <vector>
using namespace std;

class Solution {
 public:
  void swap(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2) {
    int t = matrix[x1][y1];
    matrix[x1][y1] = matrix[x2][y2];
    matrix[x2][y2] = t;
  }
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        swap(matrix, i, j, j, i);
      }
    }
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      for (int k = 0; k < n; k++) {
        swap(matrix, k, i, k, j);
      }
    }
  }
};
