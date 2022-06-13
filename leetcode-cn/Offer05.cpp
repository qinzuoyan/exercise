#include <string>
using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {
    string r;
    for (char c : s) {
      if (c == ' ') {
        r.append("%20");
      } else {
        r.push_back(c);
      }
    }
    return r;
  }
};
