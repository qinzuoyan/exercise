#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int a[1001];
        a[0] = 0;
        for (int i = 1; i <= 1000; i++) {
            a[i] = a[i-1] + i - 1;
        }
        int r = n, c = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                c++;
            }
            else {
                r += a[c];
                if (c > 1) {
                    int x = i - c - 1, y = i;
                    while (x >= 0 && y < n && s[x] == s[y]) {
                        r++; 
                        x--;
                        y++;
                    }
                }
                int x = i - 1, y = i + 1;
                while (x >= 0 && y < n && s[x] == s[y]) {
                    r++; 
                    x--;
                    y++;
                }
                c = 1;
            }
        }
        r += a[c];
        return r;
    }
};
