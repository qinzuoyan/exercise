#include <cassert>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  void calc(stack<char>& s, stack<int>& n) {
    char c = s.top();
    s.pop();
    int b = n.top();
    n.pop();
    int a = n.top();
    n.pop();
    if (c == '+') {
      n.push(a + b);
    } else if (c == '-') {
      n.push(a - b);
    } else if (c == '*') {
      n.push(a * b);
    } else {
      n.push(a / b);
    }
  }

  int calculate(string s) {
    stack<char> sign;
    stack<int> num;
    const char* p = s.data();
    char c;
    while ((c = *p)) {
      if (isspace(c)) {
        p++;
      } else if (c == '*' || c == '/') {
        sign.push(c);
        p++;
      } else if (c == '+' || c == '-') {
        if (!sign.empty()) {
          char c1 = sign.top();
          if (c1 == '+' || c1 == '-') {
            calc(sign, num);
          }
        }
        sign.push(c);
        p++;
      } else {  // number
        char* q;
        num.push(strtol(p, &q, 10));
        assert(p != q);
        p = q;
        if (!sign.empty()) {
          char c1 = sign.top();
          if (c1 == '*' || c1 == '/') {
            calc(sign, num);
          }
        }
      }
    }
    while (!sign.empty()) {
      calc(sign, num);
    }
    return num.top();
  }
};
