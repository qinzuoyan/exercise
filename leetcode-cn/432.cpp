#include <cassert>
#include <string>
#include <unordered_map>
using namespace std;

struct DListNode {
  DListNode *prev, *next;
  DListNode() : prev(nullptr), next(nullptr) {}
};

// return new head
// `insert' must not be nullptr
DListNode *insert_before(DListNode *head, DListNode *insert,
                         DListNode *before) {
  if (head == nullptr) {
    assert(before == nullptr);
    insert->prev = insert;
    insert->next = insert;
    return insert;
  }
  DListNode *prev = before->prev;
  prev->next = insert;
  insert->next = before;
  before->prev = insert;
  insert->prev = prev;
  return head == before ? insert : head;
}

// return new head
// `insert' must not be nullptr
DListNode *insert_after(DListNode *head, DListNode *insert, DListNode *after) {
  if (head == nullptr) {
    assert(after == nullptr);
    insert->prev = insert;
    insert->next = insert;
    return insert;
  }
  DListNode *next = after->next;
  after->next = insert;
  insert->next = next;
  next->prev = insert;
  insert->prev = after;
  return head;
}

// return new head (may be nullptr)
// `insert' must not be nullptr
DListNode *delete_node(DListNode *head, DListNode *node) {
  if (head == nullptr || head->next == head) {
    assert(head == node);
    return nullptr;
  }
  DListNode *prev = node->prev;
  DListNode *next = node->next;
  prev->next = next;
  next->prev = prev;
  return head == node ? next : head;
}

class AllOne {
 private:
  struct KeyNode : DListNode {
    string key;
    DListNode *count_node;
    KeyNode(const string &s) : key(s), count_node(nullptr) {}
  };

  struct CountNode : DListNode {
    int count;
    DListNode *key_node;
    CountNode(int c) : count(c), key_node(nullptr) {}
  };

  unordered_map<string, DListNode *> map_;
  DListNode *list_;

 public:
  AllOne() : list_(nullptr) {}

  void inc(string key) {
    unordered_map<string, DListNode *>::iterator it = map_.find(key);
    if (it == map_.end()) {
      KeyNode *knode = new KeyNode(key);
      map_.emplace(make_pair(key, knode));
      CountNode *cnode = (CountNode *)list_;
      if (cnode == nullptr || cnode->count != 1) {
        cnode = new CountNode(1);
        list_ = insert_before(list_, cnode, list_);
      }
      knode->count_node = cnode;
      cnode->key_node = insert_before(cnode->key_node, knode, cnode->key_node);
    } else {
      KeyNode *knode = (KeyNode *)it->second;
      CountNode *cnode = (CountNode *)knode->count_node;
      // get or new CountNode with (count+1)
      CountNode *cnodeNext = (CountNode *)cnode->next;
      if (cnodeNext->count != cnode->count + 1) {
        cnodeNext = new CountNode(cnode->count + 1);
        list_ = insert_after(list_, cnodeNext, cnode);
      }
      // delete knode from cnode
      cnode->key_node = delete_node(cnode->key_node, knode);
      if (cnode->key_node == nullptr) {
        list_ = delete_node(list_, cnode);
        delete cnode;
      }
      // insert knode to cnodeNext
      knode->count_node = cnodeNext;
      cnodeNext->key_node =
          insert_before(cnodeNext->key_node, knode, cnodeNext->key_node);
    }
  }

  void dec(string key) {
    unordered_map<string, DListNode *>::iterator it = map_.find(key);
    if (it != map_.end()) {
      KeyNode *knode = (KeyNode *)it->second;
      CountNode *cnode = (CountNode *)knode->count_node;
      CountNode *cnodePrev = nullptr;
      if (cnode->count > 1) {
        // get or new CountNode with (count-1)
        cnodePrev = (CountNode *)cnode->prev;
        if (cnodePrev->count != cnode->count - 1) {
          cnodePrev = new CountNode(cnode->count - 1);
          list_ = insert_before(list_, cnodePrev, cnode);
        }
      }
      // delete knode from cnode
      cnode->key_node = delete_node(cnode->key_node, knode);
      if (cnode->key_node == nullptr) {
        list_ = delete_node(list_, cnode);
        delete cnode;
      }
      if (cnodePrev != nullptr) {
        // insert knode into cnodePrev
        knode->count_node = cnodePrev;
        cnodePrev->key_node =
            insert_before(cnodePrev->key_node, knode, cnodePrev->key_node);
      } else {
        delete knode;
        map_.erase(it);
      }
    }
  }

  string getMaxKey() {
    if (list_ == nullptr) return "";
    CountNode *cnode = (CountNode *)(list_->prev);
    KeyNode *knode = (KeyNode *)cnode->key_node;
    return knode->key;
  }

  string getMinKey() {
    if (list_ == nullptr) return "";
    CountNode *cnode = (CountNode *)list_;
    KeyNode *knode = (KeyNode *)cnode->key_node;
    return knode->key;
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
