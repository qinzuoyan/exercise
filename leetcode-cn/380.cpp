#include <cstdlib>
#include <ctime>
#include <unordered_set>
using namespace std;

class RandomizedSet {
 public:
  RandomizedSet() { srand(time(NULL)); }

  bool insert(int val) { return _s.insert(val).second; }

  bool remove(int val) { return _s.erase(val) == 1; }

  int getRandom() {
    int k = rand() % _s.size();
    int n = _s.bucket_count(), i = 0;
    for (i = 0; i < n; i++) {
      int m = _s.bucket_size(i);
      if (k < m)
        break;
      else
        k -= m;
    }
    auto it = _s.cbegin(i);
    while (k-- > 0) ++it;
    return *it;
  }

 private:
  unordered_set<int> _s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
