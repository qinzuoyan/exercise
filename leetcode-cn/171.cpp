#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int r = 0;
        for (char c : columnTitle) {
            r = r * 26 - 'A' + c + 1;
        }
        return r;
    }
};
