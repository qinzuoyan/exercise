#ifndef  __DEQUE_H_
#define  __DEQUE_H_

#include <stdlib.h>

template <typename T>
class Deque
{
public:
    Deque(size_t sz)
    {
        _arr = new T[sz];
        _cap = sz;
        _size = 0;
        _head = 0;
        _tail = _cap - 1;
    }

    ~Deque()
    {
        delete[] _arr;
    }

    bool front(T* v) const
    {
        if (v == NULL || _size == 0)
            return false;
        *v = _arr[_head];
        return true;
    }

    bool back(T* v) const
    {
        if (v == NULL || _size == 0)
            return false;
        *v = _arr[_tail];
        return true;
    }

    bool push_front(const T& v)
    {
        if (_size == _cap)
            return false;
        _head = (_head == 0 ? _cap - 1 : _head - 1);
        _arr[_head] = v;
        ++_size;
        return true;
    }

    bool push_back(const T& v)
    {
        if (_size == _cap)
            return false;
        _tail = (_tail == _cap - 1 ? 0 : _tail + 1);
        _arr[_tail] = v;
        ++_size;
        return true;
    }

    bool pop_front()
    {
        if (_size == 0)
            return false;
        _head = (_head == _cap - 1 ? 0 : _head + 1);
        --_size;
        return true;
    }

    bool pop_back()
    {
        if (_size == 0)
            return false;
        _tail = (_tail == 0 ? _cap - 1 : _tail - 1);
        --_size;
        return true;
    }

    size_t size() const
    {
        return _size;
    }

private:
    T* _arr;
    size_t _cap, _size, _head, _tail;
};

#endif  //__DEQUE_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
