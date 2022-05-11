#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
 public:
  int minimumCardPickup(vector<int>& cards) {
    int n = cards.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
      v[i] = pair<int, int>(cards[i], i);
    }
    sort(v.begin(), v.end());
    int r = INT_MAX;
    for (int i = 1; i < n; ++i) {
      if (v[i].first == v[i - 1].first && v[i].second - v[i - 1].second < r)
        r = v[i].second - v[i - 1].second;
    }
    return r == INT_MAX ? -1 : r + 1;
  }
};
