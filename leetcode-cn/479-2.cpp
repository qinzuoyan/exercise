#include <algorithm>
#include <cstdio>
using namespace std;

// timeout

class Solution {
  int match_count = 0;

 public:
  bool match(long long n) {
    match_count++;
    char a[20];
    int c = sprintf(a, "%lld", n);
    char *i = a, *j = a + c - 1;
    while (i < j && *i == *j) {
      ++i;
      --j;
    }
    return i >= j;
  }

  int largestPalindrome(int n) {
    int m = 1;
    for (int i = 0; i < n; i++) {
      m *= 10;
    }
    m -= 1;
    long long v = (long long)m * m;
    if (match(v)) return v % 1337;
    long long r = 0;
    int mj = 0;
    for (int i = m - 1; i > 0 && mj <= m; i--) {
      for (int j = max(i, mj); j <= m; j++) {
        v = (long long)i * j;
        if (v <= r && j >= mj) {
          mj = j + 1;
        } else if (match(v)) {
          // cout << "match_count=" << match_count << ", match: " << i << "," <<
          // j << "," << v << endl;
          r = v;
          mj = j;
        }
      }
    }
    // cout << "match_count=" << match_count << endl;
    return r % 1337;
  }
};
