#include <vector>
using namespace std;

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

    T front() const
    {
        return _arr[_head];
    }

    T back() const
    {
        return _arr[_tail];
    }

    void push_front(const T& v)
    {
        _head = (_head == 0 ? _cap - 1 : _head - 1);
        _arr[_head] = v;
        ++_size;
    }

    void push_back(const T& v)
    {
        _tail = (_tail == _cap - 1 ? 0 : _tail + 1);
        _arr[_tail] = v;
        ++_size;
    }

    void pop_front()
    {
        _head = (_head == _cap - 1 ? 0 : _head + 1);
        --_size;
    }

    void pop_back()
    {
        _tail = (_tail == 0 ? _cap - 1 : _tail - 1);
        --_size;
    }

    size_t size() const
    {
        return _size;
    }

    bool empty() const
    {
        return _size == 0;
    }

private:
    T* _arr;
    size_t _cap, _size, _head, _tail;
};

class Solution {
public:
    // O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> r;
        Deque<int> q(k + 1);
        int n = nums.size();
        r.reserve(n);
        for (int i = 0; i < n; i++) {
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            if (q.front() <= i - k)
                q.pop_front();
            if (i >= k - 1)
                r.push_back(nums[q.front()]);
        }
        return r;
    }
};
