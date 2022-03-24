#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include "621.cpp"
using namespace std;

int main()
{
    Solution s;
    vector<char> tasks = {'A','A','A','B','B','C'};
    cout << s.leastInterval(tasks, 2) << endl;
	return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
