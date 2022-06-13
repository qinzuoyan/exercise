#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
using namespace std;

class Solution {
 private:
  int s;
  map<int, vector<int>> m;

 public:
  Solution(vector<vector<int>> &rects) : s(0) {
    for (auto &v : rects) {
      s += (v[2] - v[0] + 1) * (v[3] - v[1] + 1);
      m[s] = v;
    }
    srand(time(NULL));
  }

  vector<int> pick() {
    int r = rand() % s;
    auto i = m.upper_bound(r);
    r = i->first - r - 1;
    auto &v = i->second;
    int x = v[2] - v[0] + 1;
    return {v[0] + r % x, v[1] + r / x};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
