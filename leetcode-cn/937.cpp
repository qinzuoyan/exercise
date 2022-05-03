#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  struct Slice {
    const char *str;
    const char *str2;
    bool is_alpha;
    Slice() : str(nullptr), str2(nullptr), is_alpha(false) {}
    Slice(const Slice &o) : str(o.str), str2(o.str2), is_alpha(o.is_alpha) {}
    Slice(const string &s) {
      str = s.data();
      size_t pos = s.find(' ');
      str2 = str + pos + 1;
      is_alpha = isalpha(*str2);
    }
    friend bool operator<(const Slice &x, const Slice &y) {
      int c = strcmp(x.str2, y.str2);
      if (c < 0) return true;
      if (c > 0) return false;
      return strcmp(x.str, y.str) < 0;
    }
  };
  bool isAlphaLog(const string &s) {
    size_t pos = s.find(' ');
    return isalpha(s[pos + 1]);
  }
  vector<string> reorderLogFiles(vector<string> &logs) {
    int n = logs.size();
    vector<Slice> v1, v2;
    for (auto &s : logs) {
      Slice slice(s);
      if (slice.is_alpha)
        v1.push_back(slice);
      else
        v2.push_back(slice);
    }
    sort(v1.begin(), v1.end());
    vector<string> r;
    for (auto &s : v1) r.emplace_back(s.str);
    for (auto &s : v2) r.emplace_back(s.str);
    return r;
  }
};
