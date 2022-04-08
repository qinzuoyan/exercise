#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> r;
    if (s.size() < p.size()) return r;
    int sv[26], pv[26], num = 0, k;
    memset(sv, 0, sizeof(sv));
    memset(pv, 0, sizeof(pv));
    for (char c : p) {
      k = c - 'a';
      if (pv[k] == 0) num++;
      pv[k]++;
    }
    int i = 0, n = 0, ls = s.size(), lp = p.size();
    while (i < ls) {
      k = s[i] - 'a';
      if (pv[k]) {
        sv[k]++;
        if (sv[k] == pv[k])
          n++;
        else if (sv[k] == pv[k] + 1)
          n--;
      }
      if (i >= lp) {
        k = s[i - lp] - 'a';
        if (pv[k]) {
          sv[k]--;
          if (sv[k] == pv[k])
            n++;
          else if (sv[k] == pv[k] - 1)
            n--;
        }
      }
      i++;
      if (n == num) r.push_back(i - lp);
    }
    return r;
  }
};
