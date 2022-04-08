#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        if (m != n) {
            return false;
        }
        if (s == goal) {
            return true;
        }
        for (int i = 1; i < n; i++) {
            if (strncmp(s.data() + i, goal.data(), n - i) == 0 &&
                    strncmp(s.data(), goal.data() + n - i, i) == 0) {
                return true;
            }
        }
        return false;
    }
};
