#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.size(), h = -1, t, m, k = 0;
    vector<int> v(n);
    while (++h < n && s[h] != c);
    do {
      t = h;
      while (++h < n && s[h] != c);
      m = (h + t) / 2;
      while (k <= m) {
        v[k] = (k <= t ? t - k : k - t);
        k++;
      }
    } while (h < n);
    while (k < n) {
      v[k] = (k <= t ? t - k : k - t);
      k++;
    }
    return v;
  }
};
