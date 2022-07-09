#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int calc(int x, int y, char c) {
    switch (c) {
      case '+':
        return x + y;
      case '-':
        return x - y;
      case '*':
        return x * y;
    }
    return 0;
  }
  void diffWaysToCompute(vector<char>& sign, vector<int>& num, int begin,
                         int end, vector<int>& out) {
    if (begin == end) {
      out.push_back(num[begin]);
      return;
    }
    vector<int> left, right;
    for (int i = begin; i < end; ++i) {
      left.clear();
      right.clear();
      diffWaysToCompute(sign, num, begin, i, left);
      diffWaysToCompute(sign, num, i + 1, end, right);
      for (int x : left) {
        for (int y : right) {
          out.push_back(calc(x, y, sign[i]));
        }
      }
    }
  }
  vector<int> diffWaysToCompute(string expression) {
    vector<char> sign;
    vector<int> num;
    char* endptr;
    const char* s = expression.c_str();
    while (*s) {
      num.push_back(strtol(s, &endptr, 10));
      s = endptr;
      if (*s) sign.push_back(*s++);
    }
    vector<int> out;
    diffWaysToCompute(sign, num, 0, sign.size(), out);
    return out;
  }
};
