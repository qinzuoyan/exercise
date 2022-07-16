#include <algorithm>
#include <cstring>
#include <map>
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
    auto pref_it1 = pref_map.lower_bound(pref);
    ++pref[pref.size() - 1];
    auto pref_it2 = pref_map.lower_bound(pref);
    vector<int> pref_index;
    while (pref_it1 != pref_it2) {
      pref_index.push_back(pref_it1->second);
      ++pref_it1;
    }
    sort(pref_index.begin(), pref_index.end());
    auto suff_it1 = suff_map.lower_bound(suff);
    ++suff[suff.size() - 1];
    auto suff_it2 = suff_map.lower_bound(suff);
    vector<int> suff_index;
    while (suff_it1 != suff_it2) {
      suff_index.push_back(suff_it1->second);
      ++suff_it1;
    }
    sort(suff_index.begin(), suff_index.end());
    int i = pref_index.size() - 1, j = suff_index.size() - 1;
    while (i >= 0 && j >= 0) {
      if (pref_index[i] == suff_index[j])
        return pref_index[i];
      else if (pref_index[i] > suff_index[j])
        --i;
      else
        --j;
    }
    return -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
