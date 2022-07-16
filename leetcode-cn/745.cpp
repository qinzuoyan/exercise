#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class WordFilter {
  map<string, int> pref_map;
  map<string, int> suff_map;

 public:
  WordFilter(vector<string>& words) {
    for (size_t i = 0; i < words.size(); ++i) {
      auto& s = words[i];
      pref_map[s] = i;
      int x = 0, y = s.size() - 1;
      while (x < y) {
        char c = s[x];
        s[x] = s[y];
        s[y] = c;
        ++x, --y;
      }
      suff_map[s] = i;
    }
  }

  int f(string pref, string suff) {
    int pref_len = pref.size(), suff_len = suff.size();
    int x = 0, y = suff_len - 1;
    while (x < y) {
      char c = suff[x];
      suff[x] = suff[y];
      suff[y] = c;
      ++x, --y;
    }
    set<int> pref_set, suff_set;
    auto pref_it = pref_map.lower_bound(pref);
    while (pref_it != pref_map.end()) {
      if (strncmp(pref.data(), pref_it->first.data(), pref_len) != 0) break;
      pref_set.insert(pref_it->second);
      ++pref_it;
    }
    auto suff_it = suff_map.lower_bound(suff);
    while (suff_it != suff_map.end()) {
      if (strncmp(suff.data(), suff_it->first.data(), suff_len) != 0) break;
      suff_set.insert(suff_it->second);
      ++suff_it;
    }
    for (auto it = pref_set.rbegin(); it != pref_set.rend(); ++it) {
      if (suff_set.find(*it) != suff_set.end()) {
        return *it;
      }
    }
    return -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
