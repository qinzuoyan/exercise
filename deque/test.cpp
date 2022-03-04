#include "deque.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;

    Deque<int> q(2);
    assert(q.size() == 0u);

    q.push_back(1);
    assert(q.size() == 1u);
    assert(q.front(&t));
    assert(t == 1);
    assert(q.back(&t));
    assert(t == 1);

    q.push_front(2);
    assert(q.size() == 2u);
    assert(q.front(&t));
    assert(t == 2);
    assert(q.back(&t));
    assert(t == 1);

    assert(!q.push_back(3));
    assert(q.size() == 2u);
    assert(!q.push_front(3));
    assert(q.size() == 2u);

    assert(q.pop_back());
    assert(q.size() == 1u);
    assert(q.front(&t));
    assert(t == 2);
    assert(q.back(&t));
    assert(t == 2);

    assert(q.pop_front());
    assert(q.size() == 0u);
    assert(!q.pop_front());
    assert(!q.pop_back());

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
