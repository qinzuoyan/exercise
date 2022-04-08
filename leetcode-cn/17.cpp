#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> r;
    if (digits.empty()) return r;
    vector<string> m = {"abc", "def",  "ghi", "jkl",
                        "mno", "pqrs", "tuv", "wxyz"};
    string s;
    letterCombinations(m, r, s, digits, 0);
    return r;
  }

  void letterCombinations(const vector<string>& m, vector<string>& r, string& s,
                          const string& d, size_t k) {
    const string& ms = m[d[k] - '2'];
    for (char c : ms) {
      s.push_back(c);
      if (k == d.size() - 1)
        r.push_back(s);
      else
        letterCombinations(m, r, s, d, k + 1);
      s.pop_back();
    }
  }
};
