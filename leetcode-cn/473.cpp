#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool match(int *a, int n, int m, int k, int p) {
    if (k == 0)
      k = m;
    if (k == m) {
      for (int i = n - 1; i >= 0; --i) {
        if (a[i]) {
          int t = a[i];
          a[i] = 0;
          if (match(a, n, m, k - t, i - 1))
            return true;
          a[i] = t;
          return false;
        }
      }
      return true;
    }
    for (int i = p; i >= 0; --i) {
      if (a[i] && a[i] <= k) {
        int t = a[i];
        a[i] = 0;
        if (match(a, n, m, k - t, i - 1))
          return true;
        a[i] = t;
      }
    }
    return false;
  }

  bool makesquare(vector<int> &matchsticks) {
    int n = matchsticks.size(), sum = 0;
    if (n < 4)
      return false;
    for (int i : matchsticks)
      sum += i;
    if (sum % 4 != 0)
      return false;
    int m = sum / 4;
    sort(matchsticks.begin(), matchsticks.end());
    if (matchsticks[n - 1] > m)
      return false;
    int a[n];
    for (int i = 0; i < n; ++i)
      a[i] = matchsticks[i];
    return match(a, n, m, m, 0);
  }
};
