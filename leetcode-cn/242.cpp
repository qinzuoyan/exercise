#include <cstring>
#include <string>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    int a[26];
    memset(a, 0, sizeof(a));
    for (char c : s) {
      a[c - 'a']++;
    }
    for (char c : t) {
      if (--a[c - 'a'] < 0) return false;
    }
    for (int i = 0; i < 26; i++) {
      if (a[i]) return false;
    }
    return true;
  }
};
