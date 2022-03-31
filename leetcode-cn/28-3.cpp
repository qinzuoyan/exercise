#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    // O(m+n) : 12ms
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        size_t r = haystack.find(needle.c_str());
        return r == string::npos ? -1 : r;
    }
};
