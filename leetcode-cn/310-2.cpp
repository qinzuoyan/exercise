#include <cstring>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  void findLongestNodes(int n, vector<vector<int>>& n2n, int start,
                        vector<int>& ends, vector<int>& path) {
    int a[n];
    memset(a, 0, sizeof(a));
    a[start] = 1;
    vector<int> r;
    r.push_back(start);
    path.clear();
    path.resize(n);
    path[start] = start;
    while (r.size()) {
      vector<int> t;
      for (int i : r) {
        auto& v = n2n[i];
        for (int j : v) {
          if (!a[j]) {
            a[j] = 1;
            path[j] = i;
            t.push_back(j);
          }
        }
      }
      if (t.empty()) {
        break;
      } else {
        r.swap(t);
      }
    }
    ends.swap(r);
  }

  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> n2n(n);
    for (auto& v : edges) {
      n2n[v[0]].push_back(v[1]);
      n2n[v[1]].push_back(v[0]);
    }
    vector<int> ends, path;
    findLongestNodes(n, n2n, 0, ends, path);
    findLongestNodes(n, n2n, ends[0], ends, path);
    set<int> s;
    for (int i : ends) {
      vector<int> t;
      int j = i;
      t.push_back(j);
      do {
        j = path[j];
        t.push_back(j);
      } while (j != path[j]);
      if (t.size() & 1) {
        s.insert(t[t.size() / 2]);
      } else {
        s.insert(t[t.size() / 2]);
        s.insert(t[t.size() / 2 - 1]);
      }
    }
    vector<int> r;
    r.insert(r.end(), s.begin(), s.end());
    return r;
  }
};
