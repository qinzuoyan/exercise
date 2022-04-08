#include <vector>
using namespace std;

class NumArray {
 private:
  struct Node {
    int sum;
    int left, right;
    Node *lptr, *rptr;
    Node(int l, int r)
        : sum(0), left(l), right(r), lptr(nullptr), rptr(nullptr) {}
  };

  Node* _root;

  Node* construct(vector<int>& nums, int left, int right) {
    Node* node = new Node(left, right);
    if (left == right) {
      node->sum = nums[left];
      return node;
    }
    int mid = (left + right) / 2;
    node->lptr = construct(nums, left, mid);
    node->rptr = construct(nums, mid + 1, right);
    node->sum = node->lptr->sum + node->rptr->sum;
    return node;
  }

  void update(Node* node, int index, int val) {
    if (index < node->left || index > node->right) return;
    if (node->left == node->right) {
      node->sum = val;
      return;
    }
    update(node->lptr, index, val);
    update(node->rptr, index, val);
    node->sum = node->lptr->sum + node->rptr->sum;
  }

  int sumRange(Node* node, int left, int right) {
    if (node->right < left || node->left > right) return 0;
    if (left <= node->left && right >= node->right) return node->sum;
    return sumRange(node->lptr, left, right) +
           sumRange(node->rptr, left, right);
  }

 public:
  NumArray(vector<int>& nums) { _root = construct(nums, 0, nums.size() - 1); }

  void update(int index, int val) { update(_root, index, val); }

  int sumRange(int left, int right) { return sumRange(_root, left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
