#include <unordered_map>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class RandomizedSet {
 public:
  RandomizedSet() {
    srand(time(NULL));
  }

  bool insert(int val) {
    auto pr = _s.emplace(val, _v.size());
    if (pr.second)
      _v.push_back(val);
    return pr.second;
  }

  bool remove(int val) {
    auto it = _s.find(val);
    if (it == _s.end())
      return false;
    int p = it->second, t = _v.back();
    _s.erase(it);
    _v.resize(_v.size() - 1);
    if (t != val) {
      _s[t] = p;
      _v[p] = t;
    }
    return true;
  }

  int getRandom() {
    return _v[rand() % _v.size()];
  }

 private:
  unordered_map<int, int> _s; // val : pos
  vector<int> _v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
