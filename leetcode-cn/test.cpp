#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include "34-2.cpp"
using namespace std;

int main()
{
      std::priority_queue<int> mypq;

  mypq.push(30);
  mypq.push(100);
  mypq.push(25);
  mypq.push(25);
  mypq.push(40);

  std::cout << "Popping out elements...";
  while (!mypq.empty())
  {
     std::cout << ' ' << mypq.top();
     mypq.pop();
  }
  std::cout << '\n';
	return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
