#include <string>
using namespace std;

class Solution {
 public:
  string removeDigit(string number, char digit) {
    int n = number.size(), k = 0;
    for (int i = 0; i < n; ++i) {
      if (number[i] == digit) {
        k = i;
        if (i < n - 1 && number[i + 1] > digit) break;
      }
    }
    string r;
    if (k > 0) r = number.substr(0, k);
    if (k < n - 1) r += number.substr(k + 1);
    return r;
  }
};
