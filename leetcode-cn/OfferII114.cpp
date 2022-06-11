#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string alienOrder(vector<string> &words) {
    int n = words.size(), m[26][26], c[26];
    memset(m, 0, sizeof(m));
    memset(c, -1, sizeof(c));
    for (int i = 0; i < n; ++i) {
      const char *b = words[i].data();
      while (*b) {
        if (c[*b - 'a'] == -1) c[*b - 'a'] = 0;
        ++b;
      }
      if (i == 0) continue;
      const char *a = words[i - 1].data();
      b = words[i].data();
      while (*a && *a == *b) ++a, ++b;
      if (*a) {
        if (!*b) return "";
        if (m[*a - 'a'][*b - 'a'] == 0) {
          m[*a - 'a'][*b - 'a'] = 1;
          ++c[*b - 'a'];
        }
      }
    }
    string r;
    int k = 0;
    for (int i = 0; i < 26; ++i) {
      if (c[i] != -1) ++k;
    }
    int t = k + 1;
    while (k > 0 && t != k) {
      t = k;
      for (int i = 0; i < 26; ++i) {
        if (c[i] == 0) {
          r.push_back('a' + i);
          c[i] = -1;
          for (int j = 0; j < 26; ++j) {
            if (m[i][j]) --c[j];
          }
          --k;
        }
      }
    }
    return k == 0 ? r : "";
  }
};
