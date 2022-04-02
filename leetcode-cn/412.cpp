#include <string>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v(n);
        char buf[100];
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                v[i-1] = "FizzBuzz";
            }
            else if (i % 5 == 0) {
                v[i-1] = "Buzz";
            }
            else if (i % 3 == 0) {
                v[i-1] = "Fizz";
            }
            else {
                sprintf(buf, "%d", i);
                v[i-1] = buf;
            }
        }
        return v;
    }
};
