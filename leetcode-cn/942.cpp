#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  vector<int> diStringMatch(string s) {
    int n = s.size();
    int dc = 0;
    for (char c : s) {
      if (c == 'D') ++dc;
    }
    vector<int> r(n + 1);
    r[0] = dc;
    int x = dc, y = dc;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'D')
        r[i + 1] = --y;
      else
        r[i + 1] = ++x;
    }
    return r;
  }
};
