#ifndef __BINARY_INDEX_TREE_H_
#define __BINARY_INDEX_TREE_H_

#include <cstring>

class BinaryIndexTree {
public:
    // [1, n]
    BinaryIndexTree(int n) : _n(n) {
        _v = new int[_n + 1];
        memset(_v, 0, sizeof(int) * (_n + 1));
    }

    ~BinaryIndexTree() {
        delete []_v;
    }

    // 1 <= i <= n
    void update(int i, int x) {
        for (int p = i; p <= _n; p += lowbit(p)) {
            _v[p] += x;
        }
    }

    // 0 <= i <= n
    int query(int i) {
        int r = 0;
        for (int p = i; p; p -= lowbit(p)) {
            r += _v[p];
        }
        return r;
    }

    // 1 <= i <= j <= n
    int query(int i, int j) {
        return query(j) - query(i - 1);
    }


private:
    int lowbit(int i) {
        return i & (-i);
    }

    int _n;
    int* _v;
};

#endif
