#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include "30.cpp"
using namespace std;

int main()
{
    string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> v = {"fooo","barr","wing","ding","wing"};
    Solution s;
    vector<int> r = s.findSubstring(str, v);
    for (int i : r) {
        cout << i << ",";
    }
    cout << endl;
	return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
