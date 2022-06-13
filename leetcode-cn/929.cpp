#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numUniqueEmails(vector<string> &emails) {
    map<string, set<string>> m;
    for (auto &s : emails) {
      int pos = s.find_first_of('@');
      string domain = s.substr(pos + 1);
      string local;
      for (int i = 0; i < pos && s[i] != '+'; ++i) {
        if (s[i] != '.') local.push_back(s[i]);
      }
      m[domain].insert(local);
    }
    int r = 0;
    for (auto &kv : m) r += kv.second.size();
    return r;
  }
};
