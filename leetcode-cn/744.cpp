#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const char *i = &letters[0];
        const char *j = i + letters.size() - 1;
        if (*j <= target) {
            return *i;
        }
        while (i < j) {
            const char *m = i + ((j - i) >> 1);
            if (*m <= target) {
                i = m + 1;
            }
            else {
                j = m;
            }
        }
        return *i;
    }
};
