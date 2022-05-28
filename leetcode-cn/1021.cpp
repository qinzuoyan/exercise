#include <string>
using namespace std;

class Solution {
 public:
  string removeOuterParentheses(string s) {
    string r;
    int in = 0, d = 0;
    for (char c : s) {
      if (c == '(') {
        if (!in)
          in = 1;
        else {
          r.push_back(c);
          ++d;
        }
      } else {
        if (d == 0)
          in = 0;
        else {
          r.push_back(c);
          --d;
        }
      }
    }
    return r;
  }
};
