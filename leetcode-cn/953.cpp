#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isAlienSorted(vector<string> &words, string order) {
    if (words.size() == 1) return true;
    int n = words.size();
    int a[26];
    for (int i = 0; i < 26; ++i) {
      a[order[i] - 'a'] = i + 1;
    }
    for (int i = 1; i < n; ++i) {
      const char *p1 = words[i - 1].data(), *p2 = words[i].data();
      while (*p1 && *p1 == *p2) ++p1, ++p2;
      if (*p1 && (*p2 == '\0' || a[*p1 - 'a'] > a[*p2 - 'a'])) return false;
    }
    return true;
  }
};
