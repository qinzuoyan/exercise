#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkOnPath(set<pair<int, int>>& s, int r, int u, int x, int y) {
    int m = min(x / r, y / u);
    return s.find(pair<int, int>(x - m * r, y - m * u)) != s.end();;
  }
  bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {
    set<pair<int, int>> s;
    int r = 0, u = 0;
    s.emplace(pair<int, int>(0, 0));
    for (char c : command) {
      if (c == 'U')
        u++;
      else
        r++;
      s.emplace(pair<int, int>(r, u));
    }
    if (!checkOnPath(s, r, u, x, y)) {
      return false;
    }
    for (auto &v : obstacles) {
      if (v[0] <= x && checkOnPath(s, r, u, v[0], v[1])) {
        return false;
      }
    }
    return true;
  }
};
