#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (!s.empty()) {
            char *i = &s[0];
            char *j = i + s.size()-1;
            while (i < j) {
                char c = *i;
                *i++ = *j;
                *j-- = c;
            }
        }
    }
};
