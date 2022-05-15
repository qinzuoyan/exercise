#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
 public:
  void fill(const string &s, int *a) {
    memset(a, 0, sizeof(int) * 26);
    for (char c : s) {
      ++a[c - 'a'];
    }
  }
  vector<string> removeAnagrams(vector<string> &words) {
    if (words.size() == 1) return words;
    int a[26], b[26], n = words.size();
    fill(words[0], a);
    vector<string> r = {words[0]};
    for (int i = 1; i < n; ++i) {
      fill(words[i], b);
      if (memcmp(a, b, sizeof(a)) != 0) {
        r.push_back(words[i]);
        memcpy(a, b, sizeof(a));
      }
    }
    return r;
  }
};
