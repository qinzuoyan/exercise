class MyCircularDeque {
private:
  int cp_;
  int sz_;
  int h_, t_;
  int *q_;

public:
    MyCircularDeque(int k) : cp_(k), sz_(0), h_(-1), t_(0) {
      q_ = new int[k];
    }

    ~MyCircularDeque() {
      delete [] q_;
    }
    
    bool insertFront(int value) {
      if (sz_ == cp_) return false;
      ++h_;
      if (h_ == cp_) h_ = 0;
      q_[h_] = value;
      ++sz_;
      return true;
    }
    
    bool insertLast(int value) {
      if (sz_ == cp_) return false;
      --t_;
      if (t_ == -1) t_ = cp_ - 1;
      q_[t_] = value;
      ++sz_;
      return true;
    }
    
    bool deleteFront() {
      if (sz_ == 0) return false;
      --h_;
      if (h_ == -1) h_ = cp_ - 1;
      --sz_;
      return true;
    }
    
    bool deleteLast() {
      if (sz_ == 0) return false;
      ++t_;
      if (t_ == cp_) t_ = 0;
      --sz_;
      return true;
    }
    
    int getFront() {
      return sz_ > 0 ? q_[h_] : -1;
    }
    
    int getRear() {
      return sz_ > 0 ? q_[t_] : -1;
    }
    
    bool isEmpty() {
      return sz_ == 0;
    }
    
    bool isFull() {
      return sz_ == cp_;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
