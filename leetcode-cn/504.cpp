#include <string>
using namespace std;

class Solution {
 public:
  static int Array[];

  string convertToBase7(int num) {
    string r;
    if (num < 0) {
      num = -num;
      r += '-';
    }
    bool c = false;
    for (int i = 0; Array[i] > 0; i++) {
      if (num >= Array[i]) {
        int k = num / Array[i];
        num = num - Array[i] * k;
        r += '0' + k;
        c = true;
      } else if (c) {
        r += '0';
      }
    }
    r += '0' + num;
    return r;
  }
};

int Solution::Array[] = {5764801, 823543, 117649, 16807, 2401, 343, 49, 7, 0};
