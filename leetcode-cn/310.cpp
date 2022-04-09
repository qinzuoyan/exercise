#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  static const int kNoVisit = -1;
  static const int kAllVisit = -2;
  struct Stat {
    int stat;               // kNoVisit || kAllVisit || kMostVisit(>=0)
    int max0, max1;
    int max0n;
    Stat() : stat(kNoVisit), max0(0), max1(0), max0n(0) {}
  };

  int findHeightExcept(Stat* stats, vector<int>* n2n, int root,
                       int except) {
    Stat& s = stats[root];
    if (s.stat == kNoVisit) { // kNoVisit
      vector<int>& v = n2n[root];
      for (int i : v) {
        if (i != except) {
          int h = findHeightExcept(stats, n2n, i, root) + 1;
          if (h > s.max0) {
            s.max1 = s.max0;
            s.max0 = h;
            s.max0n = i;
          }
          else if ( h > s.max1) {
            s.max1 = h;
          }
        }
        s.stat = except >= 0 ? except : kAllVisit;
      }
      return s.max0;
    } else if (s.stat >= 0) { // kMostVisit
      if (s.stat == except) {
        return s.max0;
      } else {
        int h = findHeightExcept(stats, n2n, s.stat, root) + 1;
        if (h > s.max0) {
          s.max1 = s.max0;
          s.max0 = h;
          s.max0n = s.stat;
        } else if (h > s.max1) {
          s.max1 = h;
        }
        s.stat = kAllVisit;
        return s.max0n == except ? s.max1 : s.max0;
      }
    } else { // kAllVisit
      return s.max0n == except ? s.max1 : s.max0;
    }
  }

  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> n2n[n];
    for (auto& v : edges) {
      n2n[v[0]].push_back(v[1]);
      n2n[v[1]].push_back(v[0]);
    }
    Stat stats[n];
    int h[n];
    int r = INT_MAX;
    for (int i = 0; i < n; i++) {
      h[i] = findHeightExcept(stats, n2n, i, -1);
      if (h[i] < r) {
        r = h[i];
      }
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if (h[i] == r) {
        v.push_back(i);
      }
    }
    return v;
  }
};
