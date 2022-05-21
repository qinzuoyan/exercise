#include <vector>
using namespace std;

class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size();
    double max = 0;
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        for (int k = j + 1; k < n; ++k) {
          vector<int>&p0 = points[i], &p1 = points[j], &p2 = points[k];
          double s = (double)((p1[0] - p0[0]) * (p2[1] - p0[1]) -
                              (p2[0] - p0[0]) * (p1[1] - p0[1])) /
                     2;
          if (s < 0) s = -s;
          if (s > max) max = s;
        }
      }
    }
    return max;
  }
};
