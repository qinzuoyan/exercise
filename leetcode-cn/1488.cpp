#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  vector<int> avoidFlood(vector<int>& rains) {
    vector<int> ans;
    if (rains.empty()) {
      return ans;
    }
    int z = rains.size();
    ans.resize(z, 1);
    unordered_map<int, int> m;
    int k = 0;
    for (int i = 0; i < z; ++i) {
      if (rains[i] > 0) {
        ans[i] = -1;
        auto f = m.find(rains[i]);
        if (f != m.end()) {
          k = max(k, f.second + 1);
          while (k < i && rains[k] > 0) ++k;
          if (k == i) {
            ans.clear();
            return ans;
          }
          ans[k] = rains[i];
          ++k;
        }
        else {
          m[rains[i]] = i;
        }
      }
    }
  }
};
