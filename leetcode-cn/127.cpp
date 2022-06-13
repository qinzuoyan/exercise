#include <climits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class UnionFindSet {
 public:
  UnionFindSet(int initItemCount = 0) : _v(initItemCount + 1) {
    for (int i = 1; i <= initItemCount; ++i) {
      _v[i] = -1;
    }
  }
  int find(int x) { return _v[x] < 0 ? x : (_v[x] = find(_v[x])); }
  int merge(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return x;
    if (_v[x] < _v[y]) {
      // merge y to x
      _v[x] += _v[y];
      _v[y] = x;
      return x;
    } else {
      // merge x to y
      _v[y] += _v[x];
      _v[x] = y;
      return y;
    }
  }
  int new_item() {
    _v.emplace_back(-1);
    return _v.size() - 1;
  }
  int item_count() { return _v.size() - 1; }
  int diff_set_count() {
    int r = 0, n = _v.size();
    for (int i = 1; i < n; ++i) {
      if (_v[i] < 0) {
        r++;
      }
    }
    return r;
  }
  int set_size(int x) { return -_v[find(x)]; }

 private:
  std::vector<int> _v;
};

template <typename T>
class Graph {
  map<T, list<pair<T, int>>> l;

 public:
  void addEdge(T x, T y, int wt) {
    l[x].push_back({y, wt});
    l[y].push_back({x, wt});
  }

  // return INT_MAX if not reachable
  int djikstraShortestPath(T src, T dst) {
    map<T, int> dist;
    djikstraShortestPath(src, dist, &dst);
    auto pr = dist.find(dst);
    return pr == dist.end() ? INT_MAX : pr->second;
  }

  // set to INT_MAX if not reachable
  void djikstraShortestPath(T src, map<T, int> &dist, const T *dst = nullptr) {
    // Initialising dist to inf
    dist.clear();
    for (auto p : l) {
      T node = p.first;
      dist[node] = INT_MAX;
    }
    dist[src] = 0;

    // set created to get the min dist element at the beginning
    // 		dist, node
    set<pair<int, T>> s;
    s.insert({0, src});

    while (!s.empty()) {
      pair<int, T> p = *s.begin();
      if (dst && *dst == p.second) {
        return;
      }
      s.erase(s.begin());
      T currNode = p.second;
      int currNodeDist = p.first;

      // visit all nbrs of node
      for (auto nbr : l[currNode]) {
        T nbrNode = nbr.first;
        int distInBetween = nbr.second;
        int nbrNodeDist = dist[nbrNode];

        // Potential new distance = currNodeDist + distInBetween
        if (currNodeDist + distInBetween < nbrNodeDist) {
          // Update dist in both set and map
          // If node not present in set then add it
          auto pr = s.find({dist[nbrNode], nbrNode});
          if (pr != s.end()) {
            s.erase(pr);
          }
          dist[nbrNode] = currNodeDist + distInBetween;
          s.insert({dist[nbrNode], nbrNode});
        }
      }
    }
  }
};

class Solution {
 public:
  bool checkTrans(const string &a, const string &b) {
    bool diff = false;
    const char *x = a.data(), *y = b.data();
    while (*x) {
      if (*x++ != *y++) {
        if (diff)
          return false;
        else
          diff = true;
      }
    }
    return true;
  }

  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int n = wordList.size();
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) {
      m[wordList[i]] = i;
    }
    int b, e;
    auto it = m.find(endWord);
    if (it == m.end()) {
      return 0;
    } else {
      e = it->second;
    }
    it = m.find(beginWord);
    if (it == m.end()) {
      wordList.push_back(beginWord);
      b = n++;
      m[beginWord] = b;
    } else {
      b = it->second;
    }

    UnionFindSet u(n + 1);
    Graph<int> g;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (checkTrans(wordList[i], wordList[j])) {
          u.merge(i + 1, j + 1);
          g.addEdge(i, j, 1);
        }
      }
    }
    if (u.find(b + 1) != u.find(e + 1)) {
      return 0;
    }
    return g.djikstraShortestPath(b, e) + 1;
  }
};
