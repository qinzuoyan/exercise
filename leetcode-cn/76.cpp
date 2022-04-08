#include <cstring>
#include <string>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    int sv[100], tv[100];
    memset(sv, 0, sizeof(sv));
    memset(tv, 0, sizeof(tv));
    size_t num = 0;
    for (char c : t) {
      size_t k = c - 'A';
      if (tv[k] == 0) num++;
      tv[k]++;
    }
    size_t i = 0, j = 0, n = 0, pos = 0, min = s.size() + 1;
    while (j < s.size()) {
      while (j < s.size() && n < num) {
        size_t k = s[j] - 'A';
        sv[k]++;
        if (sv[k] == tv[k]) n++;
        j++;
      }
      while (i < j && n == num) {
        size_t k = s[i] - 'A';
        if (sv[k] == tv[k]) {
          if (j - i < min) {
            pos = i;
            min = j - i;
          }
          n--;
        }
        sv[k]--;
        i++;
      }
    }
    return min == s.size() + 1 ? "" : s.substr(pos, min);
  }
};
