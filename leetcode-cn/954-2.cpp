#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canReorderDoubled(vector<int>& arr) {
    if (arr.empty()) {
      return true;
    }
    int a[2][100001];
    memset(a, 0, sizeof(a));
    int c0 = 0, a0 = 0, a1 = 0;
    for (int i : arr) {
      if (i == 0) {
        c0++;
      } else if (i > 0) {
        a[0][i]++;
        a0++;
      } else {
        a[1][-i]++;
        a1++;
      }
    }
    if ((c0 & 1) || (a0 & 1) || (a1 & 1)) {
      return false;
    }
    for (int i = 0; i < 2; i++) {
      int* m = a[i];
      for (int j = 1; j <= 100000; j++) {
        if (m[j] > 0) {
          if ((m[j << 1] -= m[j]) < 0) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
