#include <vector>
#include <queue>
using namespace std;

class Solution {
    struct compare
    {
        bool reverse;
        compare(bool r = false) : reverse(r) {}
        bool operator() (const int& lhs, const int& rhs) const
        {
            return reverse ? lhs > rhs : lhs < rhs;
        }
    };

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        bool k_min = true;
        if (k > m * n / 2) {
            k_min = false;
            k = m * n - k + 1;
        }
        priority_queue<int, vector<int>, compare> q(compare(!k_min));
        for (auto& v : matrix) {
            for (int i : v) {
                if ((int)q.size() < k) {
                    q.push(i);
                }
                else if ((k_min && i < q.top())
                        || (!k_min && i > q.top())) {
                    q.push(i);
                    q.pop();
                }
            }
        }
        return q.top();
    }
};
