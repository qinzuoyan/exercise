#include <cmath>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  typedef pair<int, int> Point;
  double cos(const Point &a, const Point &m, const Point &b) {
    Point ma = {a.first - m.first, a.second - m.second};
    Point mb = {b.first - m.first, b.second - m.second};
    double ma_mb = ma.first * mb.first + ma.second * mb.second;
    double mod_ma = sqrt(ma.first * ma.first + ma.second * ma.second);
    double mod_mb = sqrt(mb.first * mb.first + mb.second * mb.second);
    double r = ma_mb / (mod_ma * mod_mb);
    return r;
  }

  vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
    if (trees.size() <= 2) return trees;
    Point p0 = {101, 101};
    set<Point> s;
    for (auto &v : trees) {
      if (v[1] < p0.second || (v[1] == p0.second && v[0] < p0.first))
        p0 = {v[0], v[1]};
      s.emplace(v[0], v[1]);
    }
    vector<vector<int>> r;
    Point p1 = {-1, p0.second}, p2 = p0;
    bool done = false;
    int round = 0;
    while (!done && s.size()) {
      double mcos = 1;
      vector<Point> v;
      for (auto &p : s) {
        if (round == 1 && p == p0) continue;
        double c = cos(p1, p2, p);
        if (abs(c - mcos) < 0.00000001) {
          v.push_back(p);
        } else if (c < mcos) {
          v.clear();
          v.push_back(p);
          mcos = c;
        }
      }
      int d = 0;
      Point t;
      for (auto &p : v) {
        r.push_back({p.first, p.second});
        s.erase(p);
        int cd = abs(p.first == p2.first ? p.second - p2.second
                                         : p.first - p2.first);
        if (cd > d) {
          d = cd;
          t = p;
        }
        if (p == p0) done = true;
      }
      if (!done) {
        p1 = p2;
        p2 = t;
      }
    }
    return r;
  }
};
