#include <string>
using namespace std;

class Solution {
 public:
  bool oneEditAway(string first, string second) {
    int n1 = first.size(), n2 = second.size();
    if (n1 == n2) {
      int k = 0;
      for (int i = 0; i < n1; ++i) {
        if (first[i] != second[i]) {
          if (k == 0)
            ++k;
          else
            return false;
        }
      }
    } else if (n1 + 1 == n2) {
      int i = 0, j = 0;
      while (i < n1) {
        if (first[i] != second[j]) {
          if (i == j)
            ++j;
          else
            return false;
        } else {
          ++i;
          ++j;
        }
      }
    } else if (n1 == n2 + 1) {
      int i = 0, j = 0;
      while (j < n2) {
        if (first[i] != second[j]) {
          if (i == j)
            ++i;
          else
            return false;
        } else {
          ++i;
          ++j;
        }
      }
    } else {
      return false;
    }
    return true;
  }
};
