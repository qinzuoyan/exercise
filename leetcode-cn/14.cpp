#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int n = strs[0].size();
    for (auto& s : strs) {
      if ((int)s.size() < n) {
        n = s.size();
      }
    }
    for (int i = 0; i < n; i++) {
      char c = strs[0][i];
      for (auto& s : strs) {
        if (c != s[i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0].substr(0, n);
  }
};
