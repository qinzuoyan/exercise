#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> v(n + 1);
    v[0].push_back("");
    string s;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {  // first component count
        s.push_back('(');
        for (string &k : v[j - 1]) {
          s += k;
          s.push_back(')');
          for (string &l : v[i - j]) {
            s += l;
            v[i].push_back(s);
            s.resize(s.size() - l.size());
          }
          s.resize(s.size() - k.size() - 1);
        }
        s.pop_back();
      }
    }
    return v[n];
  }
};
