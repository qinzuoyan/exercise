#include <cstring>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  static const int START = 0;
  static const int END = 1;

public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<int> a(n);
    stack<int> s;
    int st = 0;
    for (auto &log : logs) {
      const char *str = log.c_str();
      int p = atoi(str);
      size_t i = log.find_first_of(':') + 1;
      int f = (strncmp(str + i, "end", 3) == 0 ? END : START);
      size_t j = log.find_first_of(':', i) + 1;
      int t = atoi(str + j);
      if (f == END)
        ++t;
      if (s.size())
        a[s.top()] += t - st;
      if (f == START)
        s.push(p);
      else
        s.pop();
      st = t;
    }
    return a;
  }
};
