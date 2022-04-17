#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

class Solution {
public:
  string digitSum(string s, int k) {
    char a[101];
    strcpy(a, s.data());
    int n = s.size();
    while (n > k) {
      int c = 0, m = 0, t;
      for (int i = 0; i < n; i++) {
        c += a[i] - '0';
        if ((i + 1) % k == 0 || i == n - 1) {
          if (k <= 2) {
            t = a[i + 1];
          }
          m += sprintf(a + m, "%d", c);
          if (k <= 2) {
            a[i + 1] = t;
          }
          c = 0;
        }
      }
      n = m;
    }
    return a;
  }
};
