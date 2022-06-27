#include <cstring>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isSubstr(const char* x, const char* y) {
    while (*x && *y) {
      if (*x == *y) ++y;
      ++x;
    }
    return !*y;
  }
  int findLUSlength(vector<string>& strs) {
    int n = strs.size();
    set<int> lens;
    for (auto& s : strs) lens.insert(s.size());
    vector<string> v;
    for (auto it = lens.rbegin(); it != lens.rend(); ++it) {
      size_t len = *it;
      unordered_map<string, int> m;
      for (auto& s : strs) {
        if (s.size() == len) m[s]++;
      }
      for (auto& kv : m) {
        if (kv.second == 1) {
          bool found = false;
          for (auto& s : v) {
            if (s.size() == len) break;
            if (isSubstr(s.c_str(), kv.first.c_str())) {
              found = true;
              break;
            }
          }
          if (!found) return len;
        }
        v.push_back(kv.first);
      }
    }
    return -1;
  }
};
