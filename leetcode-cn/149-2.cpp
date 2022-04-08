#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 1) {
      return 1;
    }
    map<pair<pair<int, int>, pair<int, double>>, int> m;
    pair<pair<int, int>, pair<int, double>> x, y;  // pair<point, direction>
    for (int i = 0; i < n - 1; i++) {
      x.first.first = points[i][0];
      x.first.second = points[i][1];
      for (int j = i + 1; j < n; j++) {
        y.first.first = points[j][0];
        y.first.second = points[j][1];
        int dx = points[i][0] - points[j][0];
        double dy = points[i][1] - points[j][1];
        dy = (dx == 0 ? 1 : dy / dx);
        dx = (dx == 0 ? 0 : 1);
        x.second.first = y.second.first = dx;
        x.second.second = y.second.second = dy;
        m[x]++;
        m[y]++;
      }
    }
    int r = 0;
    for (auto pr : m) {
      if (pr.second > r) {
        r = pr.second;
      }
    }
    return r + 1;
  }
};
