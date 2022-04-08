#include <cassert>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class NumTree {
 private:
  struct Node {
    char lc, rc;
    int ln, rn;
    int max;
    int range;
  };

 public:
  NumTree(const string& s) : _s(s) {
    _n = s.size();
    _a = new Node[_n * 4];
    construct(0, _n - 1, 1);
  }

  ~NumTree() { delete[] _a; }

  int update(int i, char c) {
    if (_s[i] != c) {
      update(0, _n - 1, 1, i, c);
    }
    return _a[1].max;
  }

 private:
  Node* construct(int l, int r, int pos) {
    Node* n = &_a[pos];
    if (l == r) {
      n->lc = n->rc = _s[l];
      n->ln = n->rn = 1;
      n->max = 1;
      n->range = 1;
      return n;
    }
    int m = (l + r) / 2;
    Node* lnode = construct(l, m, pos << 1);
    Node* rnode = construct(m + 1, r, pos << 1 | 1);
    return compute(n, lnode, rnode);
  }

  Node* update(int l, int r, int pos, int i, char c) {
    Node* n = &_a[pos];
    if (l == r) {
      assert(l == i);
      _s[l] = c;
      n->lc = n->rc = c;
      return n;
    }
    int m = (l + r) / 2;
    Node* lnode = (i <= m ? update(l, m, pos << 1, i, c) : &_a[pos << 1]);
    Node* rnode =
        (i > m ? update(m + 1, r, pos << 1 | 1, i, c) : &_a[pos << 1 | 1]);
    return compute(n, lnode, rnode);
  }

  Node* compute(Node* n, Node* lnode, Node* rnode) {
    n->range = lnode->range + rnode->range;
    n->lc = lnode->lc;
    n->ln = lnode->ln;
    n->rc = rnode->rc;
    n->rn = rnode->rn;
    n->max = max(lnode->max, rnode->max);
    if (lnode->rc == rnode->lc) {
      n->max = max(n->max, lnode->rn + rnode->ln);
      if (lnode->rn == lnode->range) {
        n->ln += rnode->ln;
      }
      if (rnode->ln == rnode->range) {
        n->rn += lnode->rn;
      }
    }
    return n;
  }

  Node* _a;
  int _n;
  string _s;
};

class Solution {
 public:
  vector<int> longestRepeating(string s, string queryCharacters,
                               vector<int>& queryIndices) {
    NumTree t(s);
    vector<int> r(queryCharacters.size());
    for (size_t i = 0; i < queryCharacters.size(); i++) {
      r[i] = t.update(queryIndices[i], queryCharacters[i]);
    }
    return r;
  }
};
