#include <cctype>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    unordered_set<string> b(banned.begin(), banned.end());
    unordered_map<string, int> m;
    char a[1000];
    char *p = a;
    for (char c : paragraph) {
      if (isalpha(c)) {
        *p++ = tolower(c);
      } else if (p != a) {
        *p = '\0';
        string s(a);
        if (b.find(s) == b.end())
          m[s]++;
        p = a;
      }
    }
    if (p != a) {
      *p = '\0';
      string s(a);
      if (b.find(s) == b.end())
        m[s]++;
    }
    int n = 0;
    string r;
    for (auto pr : m) {
      if (pr.second > n) {
        n = pr.second;
        r = pr.first;
      }
    }
    return r;
  }
};
