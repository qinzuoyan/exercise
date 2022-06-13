#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canReorderDoubled(vector<int> &arr) {
    if (arr.empty()) {
      return true;
    }
    map<int, int> a[2];
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
      auto &m = a[i];
      for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > 0) {
          auto find = m.find(it->first << 1);
          if (find == m.end() || find->second < it->second) {
            return false;
          }
          find->second -= it->second;
          it->second = 0;
        }
      }
    }
    return true;
  }
};
