#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
	   int a[n+1], b[101]; 
       memset(a, -1, sizeof(a));
       a[0] = 0;
       a[1] = 1;
       for(int i = 1; i<= 100; i++) {
           b[i] = i * i;
       }
       return numSquares(a, n, b);
    }

    int numSquares(int* a, int n, int* b) {
        if (a[n] >= 0) {
            return a[n];
        }
        int m = INT_MAX;
        for (int i = 1; b[i] <= n; i++) {
            m = min(m, numSquares(a, n - b[i], b) + 1);
        }
        a[n] = m;
        return m;
    }
};
