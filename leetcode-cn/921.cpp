#include <string>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    int k = 0;
    int r = 0;
    for (char c : s) {
      if (c == '(') {
        ++k;
      } else if (c == ')') {
        if (k > 0)
          --k;
        else
          ++r;
      }
    }
    r += k;
    return r;
  }
};
