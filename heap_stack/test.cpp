#include "heap_stack.h"
#include <deque>
#include <functional>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ASSERT(hs_, size_, stack_top_, heap_top_) \
    do { \
        assert(!hs_.empty()); \
        assert(hs_.size() == size_); \
        assert(hs_.top() == stack_top_); \
        assert(hs_.heap_top() == heap_top_); \
    } while (0)

#define N 1000

int min(const std::deque<int>& dq)
{
    int r = dq.front();
    for (std::deque<int>::const_iterator it = dq.begin();
            it != dq.end(); ++it) {
        if (*it < r) {
            r = *it;
        }
    }
    return r;
}

int main(int argc, char** argv)
{
    HeapStack<int, std::less<int> > hs;

    hs.push(10); ASSERT(hs, 1, 10, 10);
    hs.push(9);  ASSERT(hs, 2, 9, 9);
    hs.push(8);  ASSERT(hs, 3, 8, 8);
    hs.push(7);  ASSERT(hs, 4, 7, 7);
    hs.push(6);  ASSERT(hs, 5, 6, 6);
    hs.push(5);  ASSERT(hs, 6, 5, 5);
    hs.push(4);  ASSERT(hs, 7, 4, 4);
    hs.push(3);  ASSERT(hs, 8, 3, 3);
    hs.push(2);  ASSERT(hs, 9, 2, 2);
    hs.push(1);  ASSERT(hs, 10, 1, 1);
    hs.push(0);  ASSERT(hs, 11, 0, 0);

    hs.pop(); ASSERT(hs, 10, 1, 1);
    hs.pop(); ASSERT(hs, 9, 2, 2);
    hs.pop(); ASSERT(hs, 8, 3, 3);
    hs.pop(); ASSERT(hs, 7, 4, 4);
    hs.pop(); ASSERT(hs, 6, 5, 5);
    hs.pop(); ASSERT(hs, 5, 6, 6);
    hs.pop(); ASSERT(hs, 4, 7, 7);
    hs.pop(); ASSERT(hs, 3, 8, 8);
    hs.pop(); ASSERT(hs, 2, 9, 9);
    hs.pop(); ASSERT(hs, 1, 10, 10);
    hs.pop();

    std::deque<int> dq;
    srand((unsigned)time(NULL));

    for (size_t i = 0; i < N; ++i) {
        int v = rand() % N;
        dq.push_back(v);
        hs.push(v);
        ASSERT(hs, dq.size(), v, min(dq));
    }

    size_t sum_size = 0;
    for (size_t i = 0; i < N * N; ++i) {
        int b = rand() % 2;
        if (dq.size() == 0 || (dq.size() < N && b)) {
            int v = rand() % N;
            dq.push_back(v);
            hs.push(v);
            ASSERT(hs, dq.size(), dq.back(), min(dq));
        }
        else {
            dq.pop_back();
            hs.pop();
            if (dq.empty()) {
                assert(hs.empty());
                assert(hs.size() == 0);
            }
            else {
                ASSERT(hs, dq.size(), dq.back(), min(dq));
            }
        }
        sum_size += hs.size();
        if (i % N == 0) {
            std::cout << (i / N) << "/" << N << std::endl;
        }
    }

    std::cout << "avg_len = " << (sum_size / (N * N)) << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
