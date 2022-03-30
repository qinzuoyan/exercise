#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, less<int>> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (q1.empty() && q2.empty()) {
            q1.push(num);
        }
        else if (q1.empty()) {
            if (num <= q2.top()) {
                q1.push(num);
            }
            else { // num > q2.top()
                q1.push(q2.top());
                q2.pop();
                q2.push(num);
            }
        }
        else if (q2.empty()) {
            if (num >= q1.top()) {
                q2.push(num);
            }
            else { // num < q1.top()
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
        }
        else {
            if (num < q1.top()) {
                q1.push(num);
                if (q1.size() > q2.size() + 1) {
                    q2.push(q1.top());
                    q1.pop();
                }
            }
            else if (num > q2.top()) {
                q2.push(num);
                if (q2.size() > q1.size() + 1) {
                    q1.push(q2.top());
                    q2.pop();
                }
            }
            else { // q1.top <= num <= q2.top()
                if (q1.size() > q2.size()) {
                    q2.push(num);
                }
                else {
                    q1.push(num);
                }
            }
        }
    }

    double findMedian() {
        if (q1.size() < q2.size()) {
            return q2.top();
        }
        else if (q1.size() > q2.size()) {
            return q1.top();
        }
        else {
            return (q1.top() + q2.top()) / (double)2;
        }
    }
};
