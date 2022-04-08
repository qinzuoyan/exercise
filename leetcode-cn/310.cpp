#include <climits>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findHeightTrees(map<pair<int, int>, int>& m, vector<vector<int>>& n2n,
                      int parent, int child) {
    int& r = m[pair<int, int>(parent, child)];
    if (r > 0) {
      return r;
    }
    vector<int>& v = n2n[child];
    int h = 0;
    for (int i : v) {
      if (i != parent) {
        h = max(h, findHeightTrees(m, n2n, child, i));
      }
    }
    r = h + 1;
    return r;
  }
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    map<pair<int, int>, int> m;
    vector<vector<int>> n2n(n);
    for (auto& v : edges) {
      n2n[v[0]].push_back(v[1]);
      n2n[v[1]].push_back(v[0]);
    }
    int r = INT_MAX;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int h = 0;
      for (int j : n2n[i]) {
        h = max(h, findHeightTrees(m, n2n, i, j));
      }
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
