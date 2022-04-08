#include <cstring>
#include <string>
using namespace std;

class Solution {
 public:
  // O(m+n) : 4ms
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    const char *p = strstr(haystack.c_str(), needle.c_str());
    return p ? p - haystack.c_str() : -1;
  }
};
