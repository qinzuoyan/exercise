#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthLongestPath(string input) {
    int cur_len = 0, tab_count = 0, r = 0;
    bool found_ext = false;
    vector<int> v;
    const char *p = input.data();
    while (true) {
      char c = *p;
      if (c == '\n' || c == '\0') {
        int s = v.empty() ? cur_len : v.back() + cur_len + 1;
        v.push_back(s);
        if (found_ext && s > r) r = s;
        if (c == '\0') break;
        cur_len = 0;
        tab_count = 0;
        found_ext = false;
      } else if (c == '\t') {
        tab_count++;
      } else {
        if (cur_len == 0) {
          v.resize(tab_count);
        }
        if (c == '.') {
          found_ext = true;
        }
        cur_len++;
      }
      p++;
    }
    return r;
  }
};
