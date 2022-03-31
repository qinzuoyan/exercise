#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    // O(m*n) : 1368ms
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        const char *p = haystack.c_str() - 1, *q = needle.c_str() - 1;
        while (*++p) {
            const char *s1 = p, *s2 = q;
            while (*s1++ == *++s2 && *s2);
            if (!*s2) return p - haystack.c_str();
        }
        return -1;
    }
};
