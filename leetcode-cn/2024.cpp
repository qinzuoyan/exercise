#include <cstring>
#include <string>
using namespace std;

class Solution {
 public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int n = answerKey.size();
    if (k >= n / 2) return n;
    int a[n], z = -1, part = 0;
    memset(a, 0, sizeof(int) * n);
    char last = '\0';
    for (char c : answerKey) {
      if (c == last) {
        a[z]++;
      } else {
        if (z % 2 == 0) part += a[z];
        ++z;
        a[z]++;
        last = c;
      }
    }
    if (z % 2 == 0) part += a[z];
    ++z;
    if (z == 1 || part <= k || (n - part) <= k) return n;
    return max(maxAnswerWithFirstHold(a, z, k),
               maxAnswerWithFirstHold(a + 1, z - 1, k));
  }

  int maxAnswerWithFirstHold(int *a, int z, int k) {
    int hold = a[0], change = 0, pos = 0, max = a[0] + k;
    for (int i = 2; i < z; i += 2) {
      change += a[i - 1];
      hold += a[i];
      while (pos < i && change > k) {
        hold -= a[pos];
        change -= a[pos + 1];
        pos += 2;
      }
      if (hold + k > max) {
        max = hold + k;
      }
    }
    return max;
  }
};
