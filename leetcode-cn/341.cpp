#include <vector>
#include <stack>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    typedef vector<NestedInteger>::const_iterator Itr;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
       its.emplace(nestedList.begin(), nestedList.end()); 
       prepare();
    }
    
    int next() {
        int r = its.top().first->getInteger();
        ++its.top().first;
        prepare();
        return r;
    }
    
    bool hasNext() {
        return its.size();
    }

private:
    void prepare() {
        while (its.size()) {
            auto& pr = its.top();
            if (pr.first == pr.second) {
                its.pop();
            }
            else if (!pr.first->isInteger()) {
                its.emplace(pr.first->getList().begin(),
                        pr.first->getList().end());
                ++pr.first;
            }
            else {
                break;
            }
        }
    }

    stack<pair<Itr,Itr>> its;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
