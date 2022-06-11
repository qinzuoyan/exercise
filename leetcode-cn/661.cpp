#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    int m = img.size(), n = img[0].size();
    int x = -1, xn, y = -1, yn;
    vector<vector<int>> r(m);
    for (int i = 0; i < m; i++) {
      r[i].resize(n);
      x = -1;
      y = -1;
      for (int j = 0; j < n; j++) {
        if (x == -1) {
          x = 0;
          xn = 0;
          if (j > 0) {
            if (i > 0) {
              x += img[i - 1][j - 1];
              xn++;
            }
            x += img[i][j - 1];
            xn++;
            if (i < m - 1) {
              x += img[i + 1][j - 1];
              xn++;
            }
          }
        }
        if (y == -1) {
          y = 0;
          yn = 0;
          if (i > 0) {
            y += img[i - 1][j];
            yn++;
          }
          y += img[i][j];
          yn++;
          if (i < m - 1) {
            y += img[i + 1][j];
            yn++;
          }
        }
        int z = 0, zn = 0;
        if (j < n - 1) {
          if (i > 0) {
            z += img[i - 1][j + 1];
            zn++;
          }
          z += img[i][j + 1];
          zn++;
          if (i < m - 1) {
            z += img[i + 1][j + 1];
            zn++;
          }
        }
        r[i][j] = floor((float)(x + y + z) / (xn + yn + zn));
        x = y;
        xn = yn;
        y = z;
        yn = zn;
      }
    }
    return r;
  }
};
