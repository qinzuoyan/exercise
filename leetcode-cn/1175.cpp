#include <cstring>
using namespace std;

class Solution {
 public:
  int numPrimeArrangements(int n) {
    int a[n + 1], c = 0;
    memset(a, 0, sizeof(a));
    for (int i = 2; i <= n; ++i) {
      if (a[i] == 0) {
        ++c;
        for (int j = 2; i * j <= n; ++j) {
          a[i * j] = 1;
        }
      }
    }
    long long k = 1;
    for (int i = 2; i <= c; ++i) {
      k *= i;
      if (k >= 1000000007) k %= 1000000007;
    }
    for (int i = 2; i <= (n - c); ++i) {
      k *= i;
      if (k >= 1000000007) k %= 1000000007;
    }
    return k;
  }
};
