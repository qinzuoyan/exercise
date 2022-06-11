#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

class BalancedBST {
  struct Node;
  typedef Node *Tree;
  struct Node {
    int item;     // Information at this node
    int ht;       // Height of this node
    int sz;       // Item count of this tree
    Node *left;   // The left subtree
    Node *right;  // The right subtree

    Node(int it, Node *lft, Node *rgt) : item(it), left(lft), right(rgt) {
      int lht = (lft == NULL ? 0 : lft->ht);
      int rht = (rgt == NULL ? 0 : rgt->ht);
      ht = 1 + std::max(lht, rht);
      int lsz = (lft == NULL ? 0 : lft->sz);
      int rsz = (rgt == NULL ? 0 : rgt->sz);
      sz = 1 + lsz + rsz;
    }
  };

 public:
  BalancedBST(bool allow_duplicate = false) : _t(NULL), _d(allow_duplicate) {}

  ~BalancedBST() { destroy(_t); }

  //=================================================
  //                lessThan
  //=================================================
  // Returns item count less than n in the tree.
  //=================================================

  int lessThan(int n) const { return lessThan(n, _t); }

  //=================================================
  //                noMoreThan
  //=================================================
  // Returns item count no more than n in the tree.
  //=================================================

  int noMoreThan(int n) const { return lessThan(n + 1, _t); }

  //=================================================
  //                at
  //=================================================
  // Returns the item at position n in the tree.
  // If n is not in range [0, size), returns 0.
  //=================================================

  int at(int n) const {
    if (n < 0 || n >= size()) {
      return 0;
    } else {
      return at(n, _t);
    }
  }

  //=================================================
  //                insert
  //=================================================
  // Inserts x into binary search tree.
  //
  // If allow_duplicate == true:
  //   If x is already a member, it does nothing.
  //
  // If allow_duplicate == false:
  //   If x is already a member, still insert and
  //   allow duplicate items in tree.
  //=================================================

  void insert(int x) { insert(x, _t); }

  //====================================================
  //                remove
  //====================================================
  // Removes one x from binary search tree.
  //
  // If x is not in tree, it does nothing.
  //
  // If allow_duplicate == true:
  //   If the are more than one x in tree, remove
  //   only one.
  //=================================================

  void remove(int x) { remove(x, _t); }

  //==========================================
  //               size
  //==========================================
  // Returns item count of the tree.
  //=================================================

  int size() const { return size(_t); }

  //==========================================
  //               height
  //==========================================
  // Returns the height of the tree.
  //=================================================

  int height() const { return height(_t); }

 private:
  //==========================================
  //               Size
  //==========================================
  // size(T) returns item count of tree T.
  //
  // Requirement: If T is nonempty, then the
  // sz field has already been set correctly
  // T.
  //==========================================

  int size(const Tree T) const { return T == NULL ? 0 : T->sz; }

  //==========================================
  //               installSize
  //==========================================
  // installSize(T) sets T->sz to item count
  // of tree T.
  //
  // Requirements:
  //   (1) T is not empty.
  //   (2) The sz field has already been set
  //       correctly in every node of each
  //       subtree of T.
  //==========================================

  void installSize(Tree T) { T->sz = 1 + size(T->left) + size(T->right); }

  //==========================================
  //               height
  //==========================================
  // height(T) returns the height of tree T.
  //
  // Requirement: If T is nonempty, then the
  // ht field has already been set correctly
  // T.
  //==========================================

  int height(const Tree T) const { return T == NULL ? 0 : T->ht; }

  //==========================================
  //               installHeight
  //==========================================
  // installHeight(T) sets T->ht to the
  // height of tree T.
  //
  // Requirements:
  //   (1) T is not empty.
  //   (2) The ht field has already been set
  //       correctly in every node of each
  //       subtree of T.
  //==========================================

  void installHeight(Tree T) {
    T->ht = 1 + std::max(height(T->left), height(T->right));
  }

  //=================================================
  //                at
  //=================================================
  // Returns the item at position n in the tree.
  // If n is not in range [0, size), returns 0.
  //
  // Requirements: If T is nonempty, the the n
  // is in range of [0, size(T)-1].
  //=================================================

  int at(int n, const Tree T) const {
    if (T == NULL) {
      return 0;
    }
    int lsz = size(T->left);
    if (n < lsz) {
      return at(n, T->left);
    } else if (n == lsz) {
      return T->item;
    } else  // n > lsz
    {
      return at(n - lsz - 1, T->right);
    }
  }

  //=================================================
  //                lessThan
  //=================================================
  // Returns item count less than n in the tree.
  //=================================================

  int lessThan(int n, const Tree T) const {
    if (T == NULL) {
      return 0;
    } else if (T->item >= n) {
      return lessThan(n, T->left);
    } else  // T->item < n
    {
      return size(T->left) + 1 + lessThan(n, T->right);
    }
  }

  //=================================================
  //                insert
  //=================================================
  // insert(x,T) inserts x into binary search tree T.
  // If x is already a member of T, it does nothing.
  //
  // This function rebalances T after the insertion
  // if necessary.  It requires that T is
  // height-balanced when insert is called.
  //=================================================

  void insert(int x, Tree &T) {
    if (T == NULL) {
      T = new Node(x, NULL, NULL);
    } else if (x < T->item) {
      insert(x, T->left);
      rebalance(T);
    } else if (x > T->item) {
      insert(x, T->right);
      rebalance(T);
    } else if (_d) {
      int hl = height(T->left);
      int hr = height(T->right);
      if (hr > hl) {
        insert(x, T->left);
        rebalance(T);
      } else {
        insert(x, T->right);
        rebalance(T);
      }
    }
  }

  //====================================================
  //               removeSmallest
  //====================================================
  // removeSmallest(T) removes the smallest value from
  // binary search tree T and returns the value that
  // was removed.
  //
  // Requirement: T must not be an empty tree.
  //
  // This function rebalances T after removing the
  // smallest value, if necessary.  It requires that T
  // is height-balanced when removeSmallest is called.
  //====================================================

  int removeSmallest(Tree &T) {
    if (T->left == NULL) {
      int result = T->item;
      Tree p = T;

      T = T->right;  // subtrees are already balanced.
      delete p;
      return result;
    } else {
      int result = removeSmallest(T->left);
      rebalance(T);
      return result;
    }
  }

  //====================================================
  //                remove
  //====================================================
  // remove(x,T) removes x from binary search tree T.
  // If x is not in T, it does nothing.
  //
  // This function rebalances T after removing x,
  // if necessary.  It requires that T is height-balanced
  // when remove is called.
  //====================================================

  void remove(int x, Tree &T) {
    if (T != NULL) {
      if (x < T->item) {
        remove(x, T->left);
        rebalance(T);
      } else if (x > T->item) {
        remove(x, T->right);
        rebalance(T);
      } else if (T->left == NULL) {
        Tree p = T;
        T = T->right;
        delete p;
      } else if (T->right == NULL) {
        Tree p = T;
        T = T->left;
        delete p;
      } else {
        T->item = removeSmallest(T->right);
        rebalance(T);
      }
    }
  }

  //==========================================
  //              singleRotateLeft
  //==========================================
  // singleRotateLeft(T) performs a single
  // rotation from right to left at the
  // root of T.
  //==========================================

  void singleRotateLeft(Tree &T) {
    Tree r = T->right;
    T->right = r->left;
    installHeight(T);
    installSize(T);

    r->left = T;
    T = r;
    installHeight(T);
    installSize(T);
  }

  //==========================================
  //              singleRotateRight
  //==========================================
  // singleRotateRight(T) performs a single
  // rotation from left to right at the
  // root of T.
  //==========================================

  void singleRotateRight(Tree &T) {
    Tree L = T->left;
    T->left = L->right;
    installHeight(T);
    installSize(T);

    L->right = T;
    T = L;
    installHeight(T);
    installSize(T);
  }

  //==========================================
  //              doubleRotateLeft
  //==========================================
  // doubleRotateLeft(T) performs a double
  // rotation from right to left at the
  // root of T.
  //==========================================

  void doubleRotateLeft(Tree &T) {
    singleRotateRight(T->right);
    singleRotateLeft(T);
  }

  //==========================================
  //              doubleRotateRight
  //==========================================
  // doubleRotateRight(T) performs a double
  // rotation from left to right at the
  // root of T.
  //==========================================

  void doubleRotateRight(Tree &T) {
    singleRotateLeft(T->left);
    singleRotateRight(T);
  }

  //==========================================
  //              rotateLeft
  //==========================================
  // rotateLeft(T) performs a rotation
  // from right to left at the root of T,
  // choosing a single or double rotation.
  //==========================================

  void rotateLeft(Tree &T) {
    Tree r = T->right;
    int zag = height(r->left);
    int zig = height(r->right);

    if (zig > zag) {
      singleRotateLeft(T);
    } else {
      doubleRotateLeft(T);
    }
  }

  //==========================================
  //              rotateRight
  //==========================================
  // rotateRight(T) performs a rotation
  // from left to right at the root of T,
  // choosing a single or double rotation.
  //==========================================

  void rotateRight(Tree &T) {
    Tree L = T->left;
    int zig = height(L->left);
    int zag = height(L->right);

    if (zig > zag) {
      singleRotateRight(T);
    } else {
      doubleRotateRight(T);
    }
  }

  //==========================================
  //              rebalance
  //==========================================
  // rebalance(T) does the following.
  //
  //   (1) Perform a rotation at T if required.
  //
  //   (2) Set the ht field of T correctly,
  //       regardless of whether or not a
  //       rotation is done.
  //
  // Requirement: T must not be empty.
  //==========================================

  void rebalance(Tree &T) {
    int hl = height(T->left);
    int hr = height(T->right);

    if (hr > hl + 1) {
      rotateLeft(T);
    } else if (hl > hr + 1) {
      rotateRight(T);
    } else {
      installHeight(T);
      installSize(T);
    }
  }

  //==========================================
  //               Destroy
  //==========================================
  // destroy(T) release all nodes of tree T.
  //==========================================

  void destroy(Tree &T) {
    if (T != NULL) {
      destroy(T->left);
      destroy(T->right);
      delete T;
    }
  }

 private:
  Tree _t;  // root of the tree
  bool _d;  // if allow dumplicate item
};

class Solution {
 public:
  // balanced binary search tree
  // O(nlog(n))
  int reversePairs(vector<int> &nums) {
    int n = nums.size(), r = 0;
    BalancedBST tr(true);
    for (int i = n - 1; i >= 0; --i) {
      r += tr.lessThan(nums[i]);
      tr.insert(nums[i]);
    }
    return r;
  }
};
