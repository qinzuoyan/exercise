#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.size(), n2 = num2.size();
        int a[n1 + n2];
        memset(a, 0, sizeof(int) * (n1 + n2));
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                a[i + j] += (num1[n1 - i - 1] - '0') * (num2[n2 - j - 1] - '0');
            }
        }
        int k = 0;
        for (int i = 0; i < n1 + n2; i++) {
            if (a[i]) {
                if (a[i] >= 10) {
                    a[i+1] += a[i] / 10;
                    a[i] = a[i] % 10;
                }
                k = i;
            }
        }
        string r;
        while (k >= 0) {
            r += '0' + a[k--];
        }
        return r;
    }
};
