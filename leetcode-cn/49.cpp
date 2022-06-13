#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> r;
    unordered_map<string, vector<string>> m;
    for (string &s : strs) {
      string o = s;
      sort(o.begin(), o.end());
      m[o].push_back(s);
    }
    for (auto &p : m) {
      r.emplace_back(move(p.second));
    }
    return r;
  }
};
