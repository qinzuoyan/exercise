#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        const char *i = s.data(), *j = s.data() + s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(*i)) i++;
            while (i < j && !isalnum(*j)) j--;
            if (toupper(*i) != toupper(*j)) break;
            i++, j--;
        }
        return i >= j;
    }
};
