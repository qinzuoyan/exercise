#include <vector>
using namespace std;

class NumArray {
private:
    int _n;
    int* _v;

    int construct(int l, int r, int i, vector<int>& nums) {
        if (l == r) {
            return (_v[i] = nums[l]);
        }
        int mid = (l + r) >> 1;
        return (_v[i] = construct(l, mid, i << 1, nums)
                + construct(mid + 1, r, i << 1 | 1, nums));
    }

    int update(int l, int r, int i, int index, int val) {
        if (r < index || l > index) {
            return _v[i];
        }
        if (l == r) {
            return (_v[i] = val);;
        }
        int mid = (l + r) >> 1;
        return (_v[i] = update(l, mid, i << 1, index, val)
                + update(mid + 1, r, i << 1 | 1, index, val));
    }

    int sumRange(int l, int r, int i, int left, int right) {
        if (r < left || l > right) {
            return 0;
        }
        if (l >= left && r <= right) {
            return _v[i];
        }
        int mid = (l + r) >> 1;
        return sumRange(l, mid, i << 1, left, right)
            + sumRange(mid + 1, r, i << 1 | 1, left, right);
    }

public:
    NumArray(vector<int>& nums) {
        _n = nums.size();
        _v = new int[_n * 4];
        construct(0, _n - 1, 1, nums);
    }

    ~NumArray() {
        delete []_v;
    }
    
    void update(int index, int val) {
        update(0, _n - 1, 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRange(0, _n - 1, 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
