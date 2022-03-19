#ifndef  __HEAP_DEQUE_H_
#define  __HEAP_DEQUE_H_

#include <stdlib.h>
#include <string.h>
#include <assert.h>

template <class T, class Compare>
class HeapDeque {
public:
    typedef T value_type;
    typedef size_t size_type;
    struct _S {
        T data;
        size_type pos;
        _S* prev;
        _S* next;
        _S(const value_type& v, size_type p) : data(v), pos(p), prev(NULL), next(NULL) {}
    };
public:
    HeapDeque() : _array(NULL), _array_len(8), _size(0), _deque_front(NULL) {
        _array = new _S*[_array_len];
        memset(_array, 0, sizeof(_S*) * _array_len);
    }
    ~HeapDeque() {
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
    void push_front(const value_type& val) {
        push(val, true);
    }
    void push_back(const value_type& val) {
        push(val, false);
    }
    void pop_front() {
        pop(true);
    }
    void pop_back() {
        pop(false);
    }
    value_type& front() {
        assert(_size != 0);
        return _deque_front->data;
    }
    const value_type& front() const {
        assert(_size != 0);
        return _deque_front->data;
    }
    value_type& back() {
        assert(_size != 0);
        return _deque_front->prev->data;
    }
    const value_type& back() const {
        assert(_size != 0);
        return _deque_front->prev->data;
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
    void push(const value_type& val, bool front) {
        if (_size == _array_len) {
            extend_array();
        }
        _S* n = new _S(val, _size);
        _array[_size] = n;
        adjust_up(_size);
        ++_size;
        if (_size == 1) {
            n->prev = n;
            n->next = n;
            _deque_front = n;
        }
        else {
            n->next = _deque_front;
            n->prev = _deque_front->prev;
            _deque_front->prev->next = n;
            _deque_front->prev = n;
            if (front)
                _deque_front = n;
        }
    }
    void pop(bool front) {
        assert(_size != 0);
        _S* n = front ? _deque_front : _deque_front->prev;
        size_type pos = n->pos;
        if (_size == 1) {
            _deque_front = nullptr;
        }
        else {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            if (front)
                _deque_front = n->next;
        }
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
    _S* _deque_front;
};

#endif  //__HEAP_DEQUE_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
