#include <string>
using namespace std;

class Solution {
public:
  bool checkOnesSegment(string s) {
    int z = s.size();
    bool o = false;
    for (int i = 1; i < z; ++i) {
      if (s[i] == '0')
        o = true;
      else if (s[i] == '1' && o)
        return false;
    }
    return true;
  }
};
