#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int s = m * n;
    vector<int> a(s);
    int i = 0, j = 0, k = 0, d = 0;
    while (k < s) {
      if (d & 1) {
        while (true) {
          a[k++] = mat[i][j];
          if (i < m - 1 && j > 0)
            ++i, --j;
          else
            break;
        }
        if (i == m - 1)
          ++j;
        else
          ++i;
      } else {
        while (true) {
          a[k++] = mat[i][j];
          if (i > 0 && j < n - 1)
            --i, ++j;
          else
            break;
        }
        if (j == n - 1)
          ++i;
        else
          ++j;
      }
      ++d;
    }
    return a;
  }
};

