#ifndef  __UNION_FIND_SET_H_
#define  __UNION_FIND_SET_H_

#include <vector>

class UnionFindSet {
public:
    UnionFindSet(int initItemCount = 0) : _v(initItemCount + 1) {
        for (int i = 1; i <= initItemCount; ++i) {
            _v[i] = -1;
        }
    }
    int find(int x) {
        return _v[x] < 0 ? x : (_v[x] = find(_v[x]));
    }
    int merge(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y)
            return x;
        if (_v[x] < _v[y]) {
            // merge y to x
            _v[x] += _v[y];
            _v[y] = x;
            return x;
        }
        else {
            // merge x to y
            _v[y] += _v[x];
            _v[x] = y;
            return y;
        }
    }
    int new_item() {
        _v.emplace_back(-1);
        return _v.size() - 1;
    }
    int item_count() {
        return _v.size() - 1;
    }
    int diff_set_count() {
        int r = 0, n = _v.size();
        for (int i = 1; i < n; ++i) {
            if (_v[i] < 0) {
                r++;
            }
        }
        return r;
    }
private:
    std::vector<int> _v;
};

#endif
