#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include "324-2.cpp"
using namespace std;

int main()
{
    Solution s;
    vector<int> v = {0,1,2,3,3,3};
    for(int i : v) {
        cout << i << ",";
    }
    cout << endl;
    s.wiggleSort(v);
    for(int i : v) {
        cout << i << ",";
    }
    cout << endl;
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
