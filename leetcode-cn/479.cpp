#include <cstdio>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

// timeout

struct N {
  int x;
  int y;
  long long v;
  N(int _x, int _y, long long _v) : x(_x), y(_y), v(_v) {}
  bool operator<(const N& o) const {
    if (v < o.v) return true;
    if (v > o.v) return false;
    return x < o.x;
  }
};

bool compare479(const N& a, const N& b) {
  if (a.v < b.v) return true;
  if (a.v > b.v) return false;
  return a.x < b.x;
}

class Solution {
  int match_count = 0;

 public:
  bool match(long long n) {
    match_count++;
    char a[20];
    int c = sprintf(a, "%lld", n);
    char *i = a, *j = a + c - 1;
    while (i < j && *i == *j) {
      ++i;
      --j;
    }
    return i >= j;
  }

  int largestPalindrome(int n) {
    int m = 1;
    for (int i = 0; i < n; i++) {
      m *= 10;
    }
    m -= 1;
    long long v = (long long)m * m;
    if (match(v)) return v % 1337;
    priority_queue<N> q;
    set<pair<int, int>> s;
    q.emplace(m, m, v);
    s.emplace(m, m);
    long long max = 0;
    while (q.size() && q.top().v > max) {
      int x = q.top().x, y = q.top().y;
      // cout << "pop: " << x << "," << y << "," << q.top().v << endl;
      q.pop();
      v = (long long)(x - 1) * y;
      if (v > max) {
        auto pr = s.emplace(x - 1, y);
        if (pr.second) {
          if (match(v)) {
            // cout << v << " : " << x-1 << "," << y << endl;
            max = v;
          }
          q.emplace(x - 1, y, v);
        }
      }
      v = (long long)x * (y - 1);
      if (v > max) {
        auto pr = s.emplace(x, y - 1);
        if (pr.second) {
          if (match(v)) {
            // cout << v << " : " << x << "," << y-1 << endl;
            max = v;
          }
          q.emplace(x, y - 1, v);
        }
      }
    }
    if (q.size()) {
      // cout << "q.top(): " << q.top().x << "," << q.top().y << endl;
    }
    // cout << "s.size(): " << s.size() << endl;
    // cout << "match_count: " << match_count << endl;
    return max;
  }
};
