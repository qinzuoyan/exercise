#include <string>
using namespace std;

class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    const char *s = sentence.c_str();
    const char *p = searchWord.c_str();
    int i = 1;
    while (*s) {
      const char *k = p;
      while (*k && *s && *k == *s)
        ++k, ++s;
      if (!*k)
        return i;
      while (*s && *s != ' ')
        ++s;
      ++i;
      while (*s && *s == ' ')
        ++s;
    }
    return -1;
  }
};
