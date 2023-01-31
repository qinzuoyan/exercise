#include <string>
using namespace std;

class Solution {
 public:
  int countAsterisks(string s) {
    int in = 0, r = 0;
    for (char c : s) {
      switch (c) {
        case '|':
          in ^= 1;
          break;
        case '*':
          if (!in) ++r;
          break;
      }
    }
    return r;
  }
};
