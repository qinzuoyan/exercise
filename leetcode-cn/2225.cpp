#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    int m = 0;
    for (auto &v : matches) m = max(m, max(v[0], v[1]));
    int lose[m + 1], match[m + 1];
    memset(lose, 0, sizeof(lose));
    memset(match, 0, sizeof(match));
    for (auto &v : matches) {
      ++match[v[0]];
      ++match[v[1]];
      ++lose[v[1]];
    }
    vector<vector<int>> r(2);
    for (int i = 0; i <= m; ++i) {
      if (match[i] > 0) {
        if (lose[i] == 0)
          r[0].push_back(i);
        else if (lose[i] == 1)
          r[1].push_back(i);
      }
    }
    return r;
  }
};
