#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> r(1 << n);
    r[1] = 1;
    int x = 1, m = 1, y;
    for (int i = 2; i <= n; i++) {
      y = x;
      m = m << 1;
      for (int j = 0; j < m; j++) {
        r[++x] = r[y--] | m;
      }
    }
    return r;
  }
};
