#include <algorithm>
#include <vector>
using namespace std;

struct R {
  int l, r;
  R(int left) : l(left), r(left) {}
  R(int left, int right) : l(left), r(right) {}
};

bool operator<(const R& x, const R& y) { return x.l < y.l; }

class RangeModule {
 private:
  vector<R> v;

 public:
  RangeModule() {}

  void addRange(int left, int right) {
    if (v.empty()) v.emplace_back(left, right);
    auto it = upper_bound(v.begin(), v.end(), R(left));
    if (it != v.begin()) {
      --it;
      if (it->r >= right) return;
      if (it->r < left)
        ++it;
      else
        left = it->l;
    }
    if (it == v.end()) {
      v.emplace_back(left, right);
      return;
    }
    auto it1 = it;
    while (it1 != v.end() && it1->l <= right) ++it1;
    if (it != it1) {
      --it1;
      it1->l = left;
      if (right > it1->r) it1->r = right;
      if (it != it1) v.erase(it, it1);
    } else {
      v.insert(it, R(left, right));
    }
  }

  bool queryRange(int left, int right) {
    if (v.empty()) return false;
    auto it = upper_bound(v.begin(), v.end(), R(left));
    if (it == v.begin()) return false;
    --it;
    return it->l <= left && it->r >= right;
  }

  void removeRange(int left, int right) {
    if (v.empty()) return;
    auto it = upper_bound(v.begin(), v.end(), R(left));
    if (it != v.begin()) {
      --it;
      if (it->r <= left) ++it;
    }
    auto it1 = it;
    while (it1 != v.end() && it1->l < right) ++it1;
    if (it == it1) return;
    if (it->l < left && it->r > right) {
      R t(right, it->r);
      it->r = left;
      v.insert(it1, t);
      return;
    }
    if (it->l < left) {
      it->r = left;
      ++it;
      if (it == it1) return;
    }
    --it1;
    if (it1->r > right)
      it1->l = right;
    else
      ++it1;
    if (it != it1) v.erase(it, it1);
  }
};
