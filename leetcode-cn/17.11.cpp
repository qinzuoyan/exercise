#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int findClosest(vector<string> &words, string word1, string word2) {
    int n = words.size();
    int k1 = -1, k2 = -1, r = n;
    for (int i = 0; i < n; ++i) {
      if (words[i] == word1) {
        if (k2 != -1 && i - k2 < r) r = i - k2;
        k1 = i;
      } else if (words[i] == word2) {
        if (k1 != -1 && i - k1 < r) r = i - k1;
        k2 = i;
      }
    }
    return r;
  }
};
