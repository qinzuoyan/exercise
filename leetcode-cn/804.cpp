#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string> &words) {
    const char *a[] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                       "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                       "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                       "...-", ".--",  "-..-", "-.--", "--.."};
    unordered_set<string> s;
    for (auto &w : words) {
      string t;
      for (char c : w) {
        t += a[c - 'a'];
      }
      s.emplace(std::move(t));
    }
    return s.size();
  }
};
