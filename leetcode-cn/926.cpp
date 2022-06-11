#include <string>
using namespace std;

class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int r0 = 0, r1 = 0;
    for (char c : s) {
      if (c == '0') {
        r1 = min(r0, r1) + 1;
      } else {
        r1 = min(r0, r1);
        r0 = r0 + 1;
      }
    }
    return min(r0, r1);
  }
};
