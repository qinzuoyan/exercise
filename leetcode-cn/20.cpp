#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<int> d;
    for (size_t i = 0; i < s.size(); i++) {
      int t = trans(s[i]);
      // ATTENTION: maybe forget t < 0
      if (t < 0 && !d.empty() && d.top() + t == 0)
        d.pop();
      else
        d.push(t);
    }
    return d.empty();
  }

  static int trans(char c) {
    switch (c) {
      case '(':
        return 1;
      case ')':
        return -1;
      case '{':
        return 2;
      case '}':
        return -2;
      case '[':
        return 3;
      case ']':
        return -3;
    }
    return 0;
  }
};
