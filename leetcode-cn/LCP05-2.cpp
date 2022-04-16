#include <deque>
#include <vector>
using namespace std;

// Time out ...
class Solution {
 public:
  const static long long M = 1000000007;

  struct N {
    N *parent;
    vector<N *> children_list;
    int members;     // subtree member count
    int self_coins;  // coins to self
    int all_coins;   // coins to all subtree
    N() : parent(nullptr), members(0), self_coins(0), all_coins(0) {}
  };

  int collectMembers(N *n) {
    if (n->members > 0) return n->members;
    n->members = 1;
    for (N *c : n->children_list) {
      n->members += collectMembers(c);
    }
    return n->members;
  }

  vector<int> bonus(int n, vector<vector<int>> &leadership,
                    vector<vector<int>> &operations) {
    N a[n + 1];
    for (auto &v : leadership) {
      N *parent = a + v[0], *child = a + v[1];
      child->parent = parent;
      parent->children_list.push_back(child);
    }
    for (int i = 1; i <= n; i++) {
      collectMembers(a + i);
    }
    vector<int> r;
    for (auto &v : operations) {
      if (v[0] == 1) {  // give one
        a[v[1]].self_coins += v[2];
      } else if (v[0] == 2) {  // give all
        a[v[1]].all_coins += v[2];
      } else {  // query all
        N *n = a + v[1];
        N *p = n->parent;
        long long c = 0;
        while (p) {
          c += p->all_coins;
          p = p->parent;
        }
        c = c * n->members;
        deque<N *> q = {n};
        while (q.size()) {
          p = q.back();
          q.pop_back();
          c += p->self_coins + p->all_coins * p->members;
          q.insert(q.end(), p->children_list.begin(), p->children_list.end());
        }
        r.push_back(c % M);
      }
    }
    return r;
  }
};
