#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
 public:
  Node* construct(vector<vector<int>>& grid, int i, int j, int n) {
    if (n == 1) return new Node(grid[i][j], true);
    n <<= 1;
    Node* n1 = construct(grid, i, j, n);
    Node* n2 = construct(grid, i, j + n, n);
    Node* n3 = construct(grid, i + n, j, n);
    Node* n4 = construct(grid, i + n, j + n, n);
    if (n1->isLeaf && n2->isLeaf && n3->isLeaf && n4->isLeaf &&
        ((n1->val && n2->val && n3->val && n4->val) ||
         (!(n1->val || n2->val || n3->val || n4->val)))) {
      delete n2;
      delete n3;
      delete n4;
      return n1;
    }
    return new Node(true, false, n1, n2, n3, n4);
  }
  Node* construct(vector<vector<int>>& grid) {
    return construct(grid, 0, 0, grid.size());
  }
};
