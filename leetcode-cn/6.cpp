#include <string>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    int n = numRows * 2 - 2, z = s.size();
    string r;
    for (int i = 0; i < numRows; i++) {
      int j = i;
      while (j < z) {
        r += s[j];
        if (i != 0 && i != numRows - 1 && j + n - i * 2 < z) {
          r += s[j + n - i * 2];
        }
        j += n;
      }
    }
    return r;
  }
};
