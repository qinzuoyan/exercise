#include "heap_stack.h"
#include "heap_deque.h"
#include <deque>
#include <functional>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ASSERT_TOP(hs_, size_, stack_top_, heap_top_) \
    do { \
        assert(!hs_.empty()); \
        assert(hs_.size() == size_); \
        assert(hs_.top() == stack_top_); \
        assert(hs_.heap_top() == heap_top_); \
    } while (0)

#define ASSERT_FRONT(hs_, size_, front_, heap_top_) \
    do { \
        assert(!hs_.empty()); \
        assert(hs_.size() == size_); \
        assert(hs_.front() == front_); \
        assert(hs_.heap_top() == heap_top_); \
    } while (0)

#define ASSERT_BACK(hs_, size_, back_, heap_top_) \
    do { \
        assert(!hs_.empty()); \
        assert(hs_.size() == size_); \
        assert(hs_.back() == back_); \
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

void testHeapStack() {
    HeapStack<int, std::less<int> > hs;

    hs.push(10); ASSERT_TOP(hs, 1, 10, 10);
    hs.push(9);  ASSERT_TOP(hs, 2, 9, 9);
    hs.push(8);  ASSERT_TOP(hs, 3, 8, 8);
    hs.push(7);  ASSERT_TOP(hs, 4, 7, 7);
    hs.push(6);  ASSERT_TOP(hs, 5, 6, 6);
    hs.push(5);  ASSERT_TOP(hs, 6, 5, 5);
    hs.push(4);  ASSERT_TOP(hs, 7, 4, 4);
    hs.push(3);  ASSERT_TOP(hs, 8, 3, 3);
    hs.push(2);  ASSERT_TOP(hs, 9, 2, 2);
    hs.push(1);  ASSERT_TOP(hs, 10, 1, 1);
    hs.push(0);  ASSERT_TOP(hs, 11, 0, 0);

    hs.pop(); ASSERT_TOP(hs, 10, 1, 1);
    hs.pop(); ASSERT_TOP(hs, 9, 2, 2);
    hs.pop(); ASSERT_TOP(hs, 8, 3, 3);
    hs.pop(); ASSERT_TOP(hs, 7, 4, 4);
    hs.pop(); ASSERT_TOP(hs, 6, 5, 5);
    hs.pop(); ASSERT_TOP(hs, 5, 6, 6);
    hs.pop(); ASSERT_TOP(hs, 4, 7, 7);
    hs.pop(); ASSERT_TOP(hs, 3, 8, 8);
    hs.pop(); ASSERT_TOP(hs, 2, 9, 9);
    hs.pop(); ASSERT_TOP(hs, 1, 10, 10);
    hs.pop();

    std::deque<int> dq;
    srand((unsigned)time(NULL));

    for (size_t i = 0; i < N; ++i) {
        int v = rand() % N;
        dq.push_back(v);
        hs.push(v);
        ASSERT_TOP(hs, dq.size(), v, min(dq));
    }

    size_t sum_size = 0;
    for (size_t i = 0; i < N * N; ++i) {
        int b = rand() % 2;
        if (dq.size() == 0 || (dq.size() < N && b)) {
            int v = rand() % N;
            dq.push_back(v);
            hs.push(v);
            ASSERT_TOP(hs, dq.size(), dq.back(), min(dq));
        }
        else {
            dq.pop_back();
            hs.pop();
            if (dq.empty()) {
                assert(hs.empty());
                assert(hs.size() == 0);
            }
            else {
                ASSERT_TOP(hs, dq.size(), dq.back(), min(dq));
            }
        }
        sum_size += hs.size();
        if (i % N == 0) {
            std::cout << (i / N) << "/" << N << std::endl;
        }
    }

    std::cout << "testHeapStack: avg_len = " << (sum_size / (N * N)) << std::endl;
}

void testHeapDeque() {
    HeapDeque<int, std::less<int> > hs;

    hs.push_front(10); ASSERT_FRONT(hs, 1, 10, 10);
    hs.push_front(9);  ASSERT_FRONT(hs, 2, 9, 9);
    hs.push_front(8);  ASSERT_FRONT(hs, 3, 8, 8);
    hs.push_front(7);  ASSERT_FRONT(hs, 4, 7, 7);
    hs.push_front(6);  ASSERT_FRONT(hs, 5, 6, 6);
    hs.push_front(5);  ASSERT_FRONT(hs, 6, 5, 5);
    hs.push_front(4);  ASSERT_FRONT(hs, 7, 4, 4);
    hs.push_front(3);  ASSERT_FRONT(hs, 8, 3, 3);
    hs.push_front(2);  ASSERT_FRONT(hs, 9, 2, 2);
    hs.push_front(1);  ASSERT_FRONT(hs, 10, 1, 1);
    hs.push_front(0);  ASSERT_FRONT(hs, 11, 0, 0);

    hs.pop_front(); ASSERT_FRONT(hs, 10, 1, 1);
    hs.pop_front(); ASSERT_FRONT(hs, 9, 2, 2);
    hs.pop_front(); ASSERT_FRONT(hs, 8, 3, 3);
    hs.pop_front(); ASSERT_FRONT(hs, 7, 4, 4);
    hs.pop_front(); ASSERT_FRONT(hs, 6, 5, 5);
    hs.pop_front(); ASSERT_FRONT(hs, 5, 6, 6);
    hs.pop_front(); ASSERT_FRONT(hs, 4, 7, 7);
    hs.pop_front(); ASSERT_FRONT(hs, 3, 8, 8);
    hs.pop_front(); ASSERT_FRONT(hs, 2, 9, 9);
    hs.pop_front(); ASSERT_FRONT(hs, 1, 10, 10);
    hs.pop_front();

    hs.push_back(10); ASSERT_BACK(hs, 1, 10, 10);
    hs.push_back(9);  ASSERT_BACK(hs, 2, 9, 9);
    hs.push_back(8);  ASSERT_BACK(hs, 3, 8, 8);
    hs.push_back(7);  ASSERT_BACK(hs, 4, 7, 7);
    hs.push_back(6);  ASSERT_BACK(hs, 5, 6, 6);
    hs.push_back(5);  ASSERT_BACK(hs, 6, 5, 5);
    hs.push_back(4);  ASSERT_BACK(hs, 7, 4, 4);
    hs.push_back(3);  ASSERT_BACK(hs, 8, 3, 3);
    hs.push_back(2);  ASSERT_BACK(hs, 9, 2, 2);
    hs.push_back(1);  ASSERT_BACK(hs, 10, 1, 1);
    hs.push_back(0);  ASSERT_BACK(hs, 11, 0, 0);

    hs.pop_back(); ASSERT_BACK(hs, 10, 1, 1);
    hs.pop_back(); ASSERT_BACK(hs, 9, 2, 2);
    hs.pop_back(); ASSERT_BACK(hs, 8, 3, 3);
    hs.pop_back(); ASSERT_BACK(hs, 7, 4, 4);
    hs.pop_back(); ASSERT_BACK(hs, 6, 5, 5);
    hs.pop_back(); ASSERT_BACK(hs, 5, 6, 6);
    hs.pop_back(); ASSERT_BACK(hs, 4, 7, 7);
    hs.pop_back(); ASSERT_BACK(hs, 3, 8, 8);
    hs.pop_back(); ASSERT_BACK(hs, 2, 9, 9);
    hs.pop_back(); ASSERT_BACK(hs, 1, 10, 10);
    hs.pop_back();

    std::deque<int> dq;
    srand((unsigned)time(NULL));

    for (size_t i = 0; i < N; ++i) {
        int v = rand() % N;
        dq.push_back(v);
        hs.push_back(v);
        ASSERT_BACK(hs, dq.size(), v, min(dq));
    }

    size_t sum_size = 0;
    for (size_t i = 0; i < N * N; ++i) {
        int b = rand() % 2;
        if (dq.size() == 0 || (dq.size() < N && b)) {
            int v = rand() % N;
            dq.push_back(v);
            hs.push_back(v);
            ASSERT_BACK(hs, dq.size(), dq.back(), min(dq));
        }
        else {
            dq.pop_back();
            hs.pop_back();
            if (dq.empty()) {
                assert(hs.empty());
                assert(hs.size() == 0);
            }
            else {
                ASSERT_BACK(hs, dq.size(), dq.back(), min(dq));
            }
        }
        sum_size += hs.size();
        if (i % N == 0) {
            std::cout << (i / N) << "/" << N << std::endl;
        }
    }

    std::cout << "testHeapDeque: avg_len = " << (sum_size / (N * N)) << std::endl;
}


int main(int argc, char** argv)
{
    testHeapStack();
    testHeapDeque();
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
