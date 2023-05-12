#include "lock_free_queue.h"

#include <gtest/gtest.h>

#include <thread>

// unit test for LockFreeQueue
TEST(LockFreeQueueTest, Basic) {
  LockFreeQueue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  int res;
  EXPECT_TRUE(queue.pop(&res));
  EXPECT_EQ(1, res);
  EXPECT_TRUE(queue.pop(&res));
  EXPECT_EQ(2, res);
  EXPECT_TRUE(queue.pop(&res));
  EXPECT_EQ(3, res);
  EXPECT_FALSE(queue.pop(&res));
}

// unit test for LockFreeQueue
TEST(LockFreeQueueTest, MultiThread) {
  LockFreeQueue<int> queue;
  std::thread t1([&queue]() {
    queue.push(1);
    queue.push(2);
    queue.push(3);
  });
  std::thread t2([&queue]() {
    queue.push(4);
    queue.push(5);
    queue.push(6);
  });
  t1.join();
  t2.join();
  std::vector<int> results;
  int res;
  while (queue.pop(&res)) {
    results.push_back(res);
  }
  EXPECT_EQ(6, results.size());
  EXPECT_EQ(1, results[0]);
  EXPECT_EQ(2, results[1]);
  EXPECT_EQ(3, results[2]);
  EXPECT_EQ(4, results[3]);
  EXPECT_EQ(5, results[4]);
  EXPECT_EQ(6, results[5]);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}