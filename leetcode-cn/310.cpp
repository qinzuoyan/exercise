#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  static const int kNoVisit = 0;
  static const int kMostVisit = 1;
  static const int kAllVisit = 2;
  struct Stat {
    int stat;               // kNoVisit || kMostVisit || kAllVisit
    pair<int, int> max[2];  // <nodeid, height>
    int unvisit;            // used only when stat == kMostVisit
    Stat() : stat(kNoVisit), unvisit(-1) { max[0].first = max[1].first = -1; }
  };

  int findHeightExcept(vector<Stat>& stats, vector<vector<int>>& n2n, int root,
                       int except) {
    Stat& s = stats[root];
    if (s.stat == kNoVisit) {
      vector<int>& v = n2n[root];
      for (int i : v) {
        if (i != except) {
          int h = findHeightExcept(stats, n2n, i, root) + 1;
          if (h > s.max[0].second) {
            s.max[1] = s.max[0];
            s.max[0] = pair<int, int>(i, h);
          } else if (h > s.max[1].second) {
            s.max[1] = pair<int, int>(i, h);
          }
        }
        if (except >= 0) {
          s.stat = kMostVisit;
          s.unvisit = except;
        } else {
          s.stat = kAllVisit;
        }
      }
      return s.max[0].second;
    } else if (s.stat == kMostVisit) {
      if (except == s.unvisit) {
        return s.max[0].second;
      } else {
        int h = findHeightExcept(stats, n2n, s.unvisit, root) + 1;
        if (h > s.max[0].second) {
          s.max[1] = s.max[0];
          s.max[0] = pair<int, int>(s.unvisit, h);
        } else if (h > s.max[1].second) {
          s.max[1] = pair<int, int>(s.unvisit, h);
        }
        s.stat = kAllVisit;
        return s.max[0].first != except ? s.max[0].second : s.max[1].second;
      }
    } else {  // kAllVisit
      return s.max[0].first != except ? s.max[0].second : s.max[1].second;
    }
  }

  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> n2n(n);
    for (auto& v : edges) {
      n2n[v[0]].push_back(v[1]);
      n2n[v[1]].push_back(v[0]);
    }
    vector<Stat> stats(n);
    int r = INT_MAX;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int h = findHeightExcept(stats, n2n, i, -1);
      if (h == r) {
        v.push_back(i);
      } else if (h < r) {
        r = h;
        v.clear();
        v.push_back(i);
      }
    }
    return v;
  }
};
