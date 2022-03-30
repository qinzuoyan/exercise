#include <vector>
#include <cstdlib>
#include <algorithm>
#include "../balanced_bst/balanced_bst.h"
using namespace std;


class MedianFinder {
    BalancedBST tr;

public:
    MedianFinder() : tr(true) {}

    void addNum(int num) {
        tr.insert(num);
    }

    double findMedian() {
        int n = tr.size();
        if (n == 0) {
            return 0.0;
        }
        else if (n % 2 == 0) {
            return (tr.at(n / 2) + tr.at(n / 2 - 1)) / (double)2;
        }
        else {
            return tr.at(n / 2);
        }
    }
};
