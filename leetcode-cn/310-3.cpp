#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return vector<int>(1);
    }
    vector<int> n2n[n];
    int degree[n];
    memset(degree, 0, sizeof(degree));
    for (auto& v : edges) {
      n2n[v[0]].push_back(v[1]);
      n2n[v[1]].push_back(v[0]);
      degree[v[0]]++;
      degree[v[1]]++;
    }
    vector<int> visit;
    int unvisit = n;
    for (int i = 0; i < n; i++) {
      if (degree[i] == 1) {
        visit.push_back(i);
        degree[i] = 0;
      }
    }
    while (unvisit > 2) {
      unvisit -= visit.size();
      vector<int> t;
      for (int i : visit) {
        for (int j : n2n[i]) {
          if (degree[j] > 0 && --degree[j] == 1) {
            t.push_back(j);
            degree[j] = 0;
          }
        }
      }
      visit.swap(t);
    }
    return visit;
  }
};
