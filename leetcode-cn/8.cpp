#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        bool sign = true;
        if (s[i] == '+') {
            i++;
        }
        else if (s[i] == '-') {
            sign = false;
            i++;
        }
        while (s[i] == '0') {
            i++;
        }
        long long r = 0;
        while (isdigit(s[i])) {
            r = r * 10 + (sign ? s[i] - '0' : '0' - s[i]);
            if (sign && r > INT_MAX) {
                return INT_MAX;
            }
            if (!sign && r < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return (int)r;
    }
};
