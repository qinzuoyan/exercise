#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    int n = pattern.size(), i = 0;
    char a[26 * 2];
    vector<string> r;
    for (auto& s : words) {
      memset(a, 0, sizeof(a));
      for (i = 0; i < n; ++i) {
        int k = pattern[i] - 'a';
        if (!a[k]) {
          if (a[26 + s[i] - 'a']++ != 0) break;
          a[k] = s[i];
        } else if (a[k] != s[i])
          break;
      }
      if (i == n) r.push_back(s);
    }
    return r;
  }
};
