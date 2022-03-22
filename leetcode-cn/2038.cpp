#include <string>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0, as = 0, bs = 0;
        for (char c : colors) {
            if (c == 'A') {
                a++;
                if (b > 0) {
                    if (b >= 3)
                        bs += b - 2;
                    b = 0;
                }
            }
            else {
                b++;
                if (a > 0) {
                    if (a >= 3)
                        as += a - 2;
                    a = 0;
                }
            }
        }
        if (a >= 3)
            as += a - 2;
        if (b >= 3)
            bs += b - 2;
        return as > bs;
    }
};
