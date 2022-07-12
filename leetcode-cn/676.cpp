#include <vector>
#include <string>
#include <map>
using namespace std;

class MagicDictionary {
 private:
  vector<string> dict;
  map<int, vector<int>> dict_idx;

 public:
  MagicDictionary() {}

  void buildDict(vector<string> dictionary) {
    dict = dictionary;
    for (size_t i = 0; i < dict.size(); ++i) {
      dict_idx[dict[i].size()].push_back(i);
    }
  }

  bool search(string searchWord) {
    int n = searchWord.size();
    auto it = dict_idx.find(n);
    if (it == dict_idx.end()) return false;
    auto& v = it->second;
    for (int p : v) {
      auto& s = dict[p];
      int k = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] != searchWord[i]) {
          if (++k > 1) break;
        }
      }
      if (k == 1) return true;
    }
    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
