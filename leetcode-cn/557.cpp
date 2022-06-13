#include <string>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    string r = s;
    char *p = &r[0], *x = nullptr;
    while (*p) {
      if (isspace(*p)) {
        if (x) {
          char *y = p - 1;
          while (x < y) {
            char c = *x;
            *x++ = *y;
            *y-- = c;
          }
          x = nullptr;
        }
      } else if (!x) {
        x = p;
      }
      p++;
    }
    if (x) {
      char *y = p - 1;
      while (x < y) {
        char c = *x;
        *x++ = *y;
        *y-- = c;
      }
    }
    return r;
  }
};
