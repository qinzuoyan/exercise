#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    char buf[100];
    sprintf(buf, "%d", x);
    int n = strlen(buf);
    int i = 0, j = n - 1;
    while (i < j && buf[i] == buf[j]) {
      i++;
      j--;
    }
    return i >= j;
  }
};
