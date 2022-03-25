#include <vector>
#include <map>
#include <set>
using namespace std;

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
    int merge(int x, int y) {
        if ((x = find(x)) == (y = find(y)))
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
    int set_size(int x) {
        return -_v[find(x)];
    }
private:
    std::vector<int> _v;
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
            vector<double>& values, vector<vector<string>>& queries) {
        vector<double> r;
        map<string, int> stoi;
        map<pair<int, int>, double> itov;
        UnionFindSet uset;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string& a = equations[i][0];
            string& b = equations[i][1];
            int ai, bi;
            auto it = stoi.find(a);
            if (it != stoi.end()) {
                ai = it->second;
            }
            else {
                ai = uset.new_item();
                stoi.emplace(a, ai);
            }
            it = stoi.find(b);
            if (it != stoi.end()) {
                bi = it->second;
            }
            else {
                bi = uset.new_item();
                stoi.emplace(b, bi);
            }
            if (ai == bi) {
                continue;
            }
            uset.merge(ai, bi);
            itov.emplace(make_pair(ai, bi), values[i]);
            itov.emplace(make_pair(bi, ai), 1 / values[i]);
        }
        for (auto& vs : queries) {
            string& a = vs[0];
            string& b = vs[1];
            int ai, bi;
            auto it = stoi.find(a);
            if (it == stoi.end()) {
                r.push_back(-1.0);
                continue;
            }
            ai = it->second;
            it = stoi.find(b);
            if (it == stoi.end()) {
                r.push_back(-1.0);
                continue;
            }
            bi = it->second;
            if (uset.find(ai) != uset.find(bi)) {
                r.push_back(-1.0);
                continue;
            }
            double v;
            set<int> visited;
            if (find(itov, visited, ai, bi, &v)) {
                r.push_back(v);
            }
            else {
                r.push_back(-1.0);
            }
        }
        return r;
    }

    bool find(map<pair<int, int>, double>& itov, set<int>& visited, int a, int b, double* v) {
        auto it = itov.find(make_pair(a, b));
        if (it != itov.end()) {
            *v = it->second;
            return true;
        }
        visited.insert(a);
        it = itov.lower_bound(make_pair(a, 0));
        while (it->first.first == a) {
            if (visited.find(it->first.second) == visited.end()
                    && find(itov, visited, it->first.second, b, v)) {
                *v *= it->second;
                return true;
            }
            it++;
        }
        return false;
    }
};

