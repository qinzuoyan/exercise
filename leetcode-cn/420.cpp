#include <cctype>
#include <map>
#include <string>
using namespace std;

class Solution {
 public:
  int strongPasswordChecker(string password) {
    int n = password.size();
    multimap<int, int> m;  // edit : len
    int len = 0, k = 0, b = 0, i = 0;
    for (; i < n; i++) {
      if (b != 7) {
        if (isupper(password[i]))
          b |= 4;
        else if (islower(password[i]))
          b |= 2;
        else if (isdigit(password[i]))
          b |= 1;
      }
      if (i > 0 && password[i] != password[i - 1]) {
        len = i - k;
        if (len >= 3) {
          if (n > 20)
            m.emplace(len % 3 + 1, len);
          else
            m.emplace((len + 1) % 3 + 1, len);
        }
        k = i;
      }
    }
    len = i - k;
    if (len >= 3) {
      if (n > 20)
        m.emplace(len % 3 + 1, len);
      else
        m.emplace((len + 1) % 3 + 1, len);
    }
    int r = 0, an = (b >> 2) + ((b & 2) >> 1) + (b & 1);
    if (n > 20) {
      // delete
      while (n > 20 && m.size()) {
        len = m.begin()->second;
        m.erase(m.begin());
        len--;
        if (len >= 3) {
          m.emplace(len % 3 + 1, len);
        }
        r++;
        n--;
      }
      if (n > 20) {
        r += n - 20;
      }
    } else if (n < 6) {
      // insert
      while (n < 6 && m.size()) {
        len = m.begin()->second;
        m.erase(m.begin());
        len -= 2;
        if (len >= 3) {
          m.emplace((len + 1) % 3 + 1, len);
        }
        an++;
        r++;
        n++;
      }
      if (n < 6) {
        int e = 6 - n;
        an += e;
        r += e;
      }
    }
    // modify
    for (auto &pr : m) {
      int e = pr.second / 3;
      an += e;
      r += e;
    }
    if (an < 3) {
      r += 3 - an;
    }
    return r;
  }
};
