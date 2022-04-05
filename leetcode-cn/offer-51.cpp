#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class BinaryIndexTree {
private:
    int _n;
    int *_v;
    int lowbit(int i) {
        return i & (-i);
    }
public:
    // [1, n]
    BinaryIndexTree(int n) : _n(n){
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
};

class Solution {
public:
    // sparse binary index tree
    // O(nlog(n))
    int reversePairs(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> m;
        int n = nums.size(), r = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if(i == 0 || (i > 0 && sorted[i] != sorted[i - 1])) {
                m.emplace(sorted[i], ++k);
            }
        }
        BinaryIndexTree tr(k);
        for (int i = n - 1; i >= 0; --i) {
            int idx = m[nums[i]];
            r += tr.query(idx - 1);
            tr.update(idx, 1);
        }
        return r;
    }
};
