#ifndef LOCK_FREE_QUEUE_LOCK_FREE_QUEUE_H_
#define LOCK_FREE_QUEUE_LOCK_FREE_QUEUE_H_

#include <atomic>

// LockFreeQueue is a lock-free queue implementation.
// Refer to <https://coolshell.cn/articles/8239.html>.
// It is thread-safe.
// It is not copyable.
template <typename T>
class LockFreeQueue final {
 private:
  struct Node {
    T data;
    std::atomic<Node*> next;
    std::atomic<int> counter;
    Node() : next(nullptr) {}
    explicit Node(T&& dt) : data(std::move(dt)), next(nullptr), counter(1) {}
    explicit Node(const T& dt) : data(dt), next(nullptr), counter(1) {}
  };

 public:
  LockFreeQueue() : head_(new Node()), tail_(head_.load()) {}
  LockFreeQueue(const LockFreeQueue&) = delete;
  LockFreeQueue& operator=(const LockFreeQueue&) = delete;
  ~LockFreeQueue() {
    while (Node* const old_head = head_.load()) {
      head_.store(old_head->next.load());
      delete old_head;
    }
  }

  void push(const T& new_value) { push_node(new Node(new_value)); }

  void push(T&& new_value) { push_node(new Node(std::move(new_value))); }

  bool pop(T* res) {
    Node *h = nullptr, *t = nullptr, *n = nullptr;
    while (true) {
      // load head, tail and the next node of head
      h = head_.load();
      t = tail_.load();
      n = h->next.load();
      if (h == t) {
        // if head and tail are the same
        if (n == nullptr) {
          // if the next node of head is null, which means the queue is empty,
          // then return false
          return false;
        } else {
          // if the next node of head is not null, which means tail is out of
          // date, then move tail to the next node of head, and continue
          tail_.compare_exchange_weak(t, n);
          continue;
        }
      }
      // because n may be released by other thread, so we should use a reference
      // counter to avoid access to a released node
      acquire_node(n);
      if (head_.compare_exchange_weak(h, n)) {
        // if move forward head successfully, then move data to res, release the
        // old head node, and break
        *res = std::move(n->data);
        release_node(n);
        release_node(h);
        break;
      }
      release_node(n);
    }
    return true;
  }

 private:
  void push_node(Node* node) {
    Node *t = nullptr, *n = nullptr;
    while (true) {
      // load tail and the next node of tail
      t = tail_.load();
      n = t->next.load();
      // if tail is not the last node, move tail to the next node, and continue
      if (n != nullptr) {
        tail_.compare_exchange_weak(t, n);
        continue;
      }
      // if add node to the next of tail successfully, break
      if (t->next.compare_exchange_weak(n, node)) {
        break;
      }
    }
    // update tail to the new node
    tail_.compare_exchange_weak(t, node);
  }

  void acquire_node(Node* node) { node->counter.fetch_add(1); }

  void release_node(Node* node) {
    if (node->counter.fetch_sub(1) == 1) {
      delete node;
    }
  }

  std::atomic<Node*> head_;
  std::atomic<Node*> tail_;
};

#endif  // LOCK_FREE_QUEUE_LOCK_FREE_QUEUE_H_