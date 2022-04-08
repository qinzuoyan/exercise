#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> v(n + 1);
    string s;
    for (int i = 0; i <= n; i++) {
      generateParenthesis(v, i, s, i);
    }
    return v[n];
  }

  void generateParenthesis(vector<vector<string>>& v, int n, string& s, int k) {
    if (k == 0) {
      v[n].push_back(s);
      return;
    }
    for (int i = 1; i <= k; i++) {
      s.push_back('(');
      for (string& j : v[i - 1]) {
        s += j;
        s.push_back(')');
        generateParenthesis(v, n, s, k - i);
        s.resize(s.size() - j.size() - 1);
      }
      s.pop_back();
    }
  }
};
