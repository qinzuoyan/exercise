#include <string>
using namespace std;

class Solution {
 public:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  string toGoatLatin(string sentence) {
    string r;
    const char *p = sentence.data(), *h = nullptr;
    int i = 0;
    while (true) {
      if (isalpha(*p)) {
        if (!h) h = p;
      } else {
        ++i;
        if (isVowel(tolower(*h))) {
          r.append(h, p - h);
        } else {
          if (p - h > 1) r.append(h + 1, p - h - 1);
          r.push_back(*h);
        }
        r.append("ma");
        for (int j = 0; j < i; j++) r.push_back('a');
        if (*p)
          r.push_back(*p);
        else
          break;
        h = nullptr;
      }
      ++p;
    }
    return r;
  }
};
