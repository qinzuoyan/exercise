#include <cstdlib>
#include <cstring>
#include <cassert>
#include <functional>
using namespace std;

template <class T, class Compare = less<T>>
class HeapStack {
public:
    typedef T value_type;
    typedef size_t size_type;
    struct _S {
        T data;
        size_type pos;
        _S* next;
        _S(const value_type& v, size_type p) : data(v), pos(p), next(NULL) {}
    };
public:
    HeapStack() : _array(NULL), _array_len(8), _size(0), _stack_top(NULL) {
        _array = new _S*[_array_len];
        memset(_array, 0, sizeof(_S*) * _array_len);
    }
    ~HeapStack() {
        for (size_type i = 0; i < _size; ++i) {
            delete _array[i];
        }
        delete []_array;
    }
    size_type size() const {
        return _size;
    }
    bool empty() const {
        return _size == 0;
    }
    void push(const value_type& val) {
        if (_size == _array_len) {
            extend_array();
        }
        _S* n = new _S(val, _size);
        _array[_size] = n;
        adjust_up(_size);
        ++_size;
        n->next = _stack_top;
        _stack_top = n;
    }
    void pop() {
        assert(_size != 0);
        _S* n = _stack_top;
        size_type pos = _stack_top->pos;
        _stack_top = _stack_top->next;
        delete n;
        _array[pos] = NULL;
        --_size;
        if (pos == _size) {
            return;
        }
        swap(pos, _size);
        if (adjust_up(pos) == pos) {
            adjust_down(pos);
        }
    }
    value_type& top() {
        assert(_size != 0);
        return _stack_top->data;
    }
    const value_type& top() const {
        assert(_size != 0);
        return _stack_top->data;
    }
    value_type& heap_top() {
        assert(_size != 0);
        return _array[0]->data;
    }
    const value_type& heap_top() const {
        assert(_size != 0);
        return _array[0]->data;
    }
private:
    void extend_array() {
        _array_len = _array_len << 1;
        _S** new_array = new _S*[_array_len];
        memcpy(new_array, _array, sizeof(_S*) * _size);
        memset(&new_array[_size], 0, sizeof(_S*) * _size);
        delete []_array;
        _array = new_array;
    }
    size_type adjust_up(size_type i) {
        while (i > 0) {
            size_type p = parent(i);
            if (_cmp(_array[i]->data, _array[p]->data)) {
                // _array[i] < _array[j]
                swap(i, p);
                i = p;
            }
            else {
                break;
            }
        }
        return i;
    }
    size_type adjust_down(size_type i) {
        size_type lc = left_child(i);
        while (lc < _size) {
            size_type min = i;
            if (_cmp(_array[lc]->data, _array[min]->data)) {
                min = lc;
            }
            size_type rc = lc + 1;
            if (rc < _size && _cmp(_array[rc]->data, _array[min]->data)) {
                min = rc;
            }
            if (min != i) {
                swap(i, min);
                i = min;
                lc = left_child(i);
            }
            else {
                break;
            }
        }
        return i;
    }
    size_type parent(size_type i) {
        return (i - 1) / 2;
    }
    size_type left_child(size_type i) {
        return i * 2 + 1;
    }
    void swap(size_type i, size_type j) {
        _S* t = _array[i];
        _array[i] = _array[j];
        _array[j] = t;
        if (_array[i]) {
            _array[i]->pos = i;
        }
        if (_array[j]) {
            _array[j]->pos = j;
        }
    }
private:
    Compare _cmp;
    _S** _array;
    size_type _array_len;
    size_type _size;
    _S* _stack_top;
};

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        _h.push(val);
    }
    
    void pop() {
        _h.pop();
    }
    
    int top() {
        return _h.top();
    }
    
    int getMin() {
        return _h.heap_top();
    }
    
private:
    HeapStack<int> _h;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
