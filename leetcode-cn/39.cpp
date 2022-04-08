#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> r;
    sort(candidates.begin(), candidates.end());
    int i = candidates.size() - 1;
    while (i >= 0 && candidates[i] > target) i--;
    if (i < 0) return r;
    candidates.resize(i + 1);
    vector<int> t;
    combinationSum(r, t, candidates, target, 0);
    return r;
  }

  void combinationSum(vector<vector<int>>& r, vector<int>& t,
                      const vector<int>& c, int target, int k) {
    if (target == 0) {
      r.push_back(t);
      return;
    }
    if (k >= (int)c.size() || c[k] > target) {
      return;
    }
    combinationSum(r, t, c, target, k + 1);
    int n = t.size();
    while (target >= c[k]) {
      t.push_back(c[k]);
      combinationSum(r, t, c, target - c[k], k + 1);
      target -= c[k];
    }
    t.resize(n);
  }
};
