#include <cstring>
#include <string>
using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    int a[n + 1];
    memset(a, 0, sizeof(int) * (n + 1));
    a[n] = 1;
    a[n - 1] = (s[n - 1] == '0' ? 0 : 1);
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] != '0') {
        a[i] += a[i + 1];
      }
      if (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6')) {
        a[i] += a[i + 2];
      }
    }
    return a[0];
  }
};
