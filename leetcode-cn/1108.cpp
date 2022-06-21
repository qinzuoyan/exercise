#include <string>
using namespace std;

class Solution {
 public:
  string defangIPaddr(string address) {
    string r;
    for (char c : address) {
      if (c == '.')
        r += "[.]";
      else
        r.push_back(c);
    }
    return r;
  }
};
