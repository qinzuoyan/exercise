#include <cstdlib>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int evalRPN(vector<string> &tokens) {
    stack<int> s;
    for (auto &t : tokens) {
      if (t == "+" || t == "-" || t == "*" || t == "/") {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        if (t == "+")
          s.push(a + b);
        else if (t == "-")
          s.push(a - b);
        else if (t == "*")
          s.push(a * b);
        else
          s.push(a / b);
      } else {
        s.push(atoi(t.c_str()));
      }
    }
    return s.top();
  }
};
