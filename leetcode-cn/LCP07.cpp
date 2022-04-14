#include <vector>
using namespace std;

class Solution {
 public:
  void run(int n, vector<int>* a, int k, int i, int* r) {
    if (k == 0) {
      if (i == n - 1) {
        (*r)++;
      }
    }
    else {
      for (int j : a[i]) {
        run(n, a, k - 1, j, r);
      }
    }
  }

  int numWays(int n, vector<vector<int>>& relation, int k) {
    int r = 0;
    vector<int> a[n];
    for (auto& v : relation) {
      a[v[0]].push_back(v[1]);
    }
    run(n, a, k, 0, &r);
    return r;
  }
};
