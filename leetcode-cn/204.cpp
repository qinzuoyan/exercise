#include <cstring>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int a[n+1], s = 0;
        memset(a, 0, sizeof(int) * (n+1));
        for (int i = 2; i < n; i++) {
            if (!a[i]) { // found one
                if (i < 3000) {
                    for (int j = i * i; j <= n; j += i) {
                        a[j] = 1;
                    }
                }
                s++;
            }
        }
        return s;
    }
};
