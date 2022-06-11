#include <cstdlib>
#include <string>
using namespace std;

class Solution {
 public:
  int convertTime(string current, string correct) {
    current[2] = '\0';
    int h1 =
        (current[0] == '0' ? atoi(current.data() + 1) : atoi(current.data()));
    int m1 = atoi(current.data() + 3);
    correct[2] = '\0';
    int h2 =
        (correct[0] == '0' ? atoi(correct.data() + 1) : atoi(correct.data()));
    int m2 = atoi(correct.data() + 3);
    if (m2 < m1) {
      m2 += 60;
      --h2;
    }
    int r = h2 - h1, d = m2 - m1;
    if (d >= 15) {
      r += d / 15;
      d %= 15;
    }
    if (d >= 5) {
      r += d / 5;
      d %= 5;
    }
    return r + d;
  }
};
