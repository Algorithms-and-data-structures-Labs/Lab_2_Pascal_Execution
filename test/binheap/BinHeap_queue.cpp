#include <gtest/gtest.h>

#include "BinHeap/BinHeap.h"

using namespace BinHeap;

TEST(PriorityQueueTest, EnqueueAndDequeue) {
  BinHeap::PriorityQueue<int> pq;
  pq.Enqueue(5);
  pq.Enqueue(10);
  pq.Enqueue(3);

  ASSERT_EQ(pq.Dequeue(), 10);
  ASSERT_EQ(pq.Dequeue(), 5);
  ASSERT_EQ(pq.Dequeue(), 3);
}

TEST(PriorityQueueTest, Peek) {
  BinHeap::PriorityQueue<int> pq;
  pq.Enqueue(5);
  pq.Enqueue(10);
  pq.Enqueue(3);

  ASSERT_EQ(pq.Peek(), 10);

  pq.Dequeue();
  ASSERT_EQ(pq.Peek(), 5);
}

TEST(PriorityQueueTest, Count) {
  BinHeap::PriorityQueue<int> pq;
  pq.Enqueue(5);
  pq.Enqueue(10);
  pq.Enqueue(3);

  ASSERT_EQ(pq.Count(), 3);

  pq.Dequeue();
  ASSERT_EQ(pq.Count(), 2);
}

TEST(PriorityQueueTest, EmptyQueue) {
  BinHeap::PriorityQueue<int> pq;

  ASSERT_EQ(pq.Count(), 0);
  ASSERT_ANY_THROW(pq.Peek());
  ASSERT_ANY_THROW(pq.Dequeue());
}

TEST(PriorityQueueTest, EnqueueWithNegativeValues) {
  BinHeap::PriorityQueue<int> pq;
  pq.Enqueue(-5);
  pq.Enqueue(10);
  pq.Enqueue(-3);

  ASSERT_EQ(pq.Peek(), 10);
  ASSERT_EQ(pq.Count(), 3);
}

TEST(PriorityQueueTest, EnqueueWithStrings) {
  BinHeap::PriorityQueue<std::string> pq;
  pq.Enqueue("apple");
  pq.Enqueue("banana");
  pq.Enqueue("cherry");

  ASSERT_EQ(pq.Peek(), "cherry");
  ASSERT_EQ(pq.Count(), 3);
}

TEST(PriorityQueueTest, DequeueEmptyQueue) {
  BinHeap::PriorityQueue<int> pq;

  ASSERT_ANY_THROW(pq.Dequeue());
}

TEST(PriorityQueueTest, EnqueueAndDequeueAlternate) {
  BinHeap::PriorityQueue<int> pq;
  pq.Enqueue(1);
  pq.Enqueue(3);
  pq.Enqueue(2);

  ASSERT_EQ(pq.Dequeue(), 3);
  ASSERT_EQ(pq.Dequeue(), 2);
  ASSERT_EQ(pq.Dequeue(), 1);
}

TEST(PriorityQueueTest, PeekEmptyQueue) {
  BinHeap::PriorityQueue<int> pq;

  ASSERT_ANY_THROW(pq.Peek());
}

TEST(PriorityQueueTest, EnqueueAndDequeueEqualValues) {
  BinHeap::PriorityQueue<int> pq;
  pq.Enqueue(2);
  pq.Enqueue(2);
  pq.Enqueue(2);

  ASSERT_EQ(pq.Dequeue(), 2);
  ASSERT_EQ(pq.Dequeue(), 2);
  ASSERT_EQ(pq.Dequeue(), 2);
}
