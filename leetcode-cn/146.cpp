#include <unordered_map>
using namespace std;

class LRUCache {
 private:
  struct Node {
    int k, v;
    Node *prev, *next;
    Node() : k(0), v(0), prev(nullptr), next(nullptr) {}
    Node(int _k, int _v) : k(_k), v(_v), prev(nullptr), next(nullptr) {}
  };

 public:
  // capacity >= 1
  LRUCache(int capacity) : list_(nullptr), cap_(capacity), num_(0) {}

  ~LRUCache() {
    Node* n = list_;
    while (n) {
      Node* t = n->next;
      delete n;
      n = t;
      if (n == list_) break;
    }
  }

  int get(int key) {
    unordered_map<int, Node*>::iterator it = map_.find(key);
    if (it == map_.end()) return -1;
    visit(it->second);
    return it->second->v;
  }

  void put(int key, int value) {
    unordered_map<int, Node*>::iterator it = map_.find(key);
    if (it == map_.end()) {
      Node* n = new Node(key, value);
      map_[key] = n;
      insert(n);
      num_++;
    } else {
      it->second->v = value;
      visit(it->second);
    }
    if (num_ > cap_) {
      Node* n = list_->prev;
      pickoff(n);
      map_.erase(n->k);
      delete n;
      num_--;
    }
  }

 private:
  // assert(num_ >= 1);
  void visit(Node* n) {
    if (n != list_) {
      pickoff(n);
      insert(n);
    }
  }

  // assert(num_ >= 0);
  void insert(Node* n) {
    if (list_ == nullptr) {
      n->next = n;
      n->prev = n;
    } else {
      n->next = list_;
      n->prev = list_->prev;
      list_->prev->next = n;
      list_->prev = n;
      list_ = n;
    }
    list_ = n;
  }

  // assert(num_ >= 2);
  void pickoff(Node* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
  }

  unordered_map<int, Node*> map_;
  Node* list_;
  int cap_;
  int num_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
