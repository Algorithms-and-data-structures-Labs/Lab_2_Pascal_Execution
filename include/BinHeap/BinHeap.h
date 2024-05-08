#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

namespace BinHeap {

template <typename T>
class PriorityQueue {
 private:
  vector<T> data;

 public:
  PriorityQueue() {}

  void Enqueue(T item) {
    data.push_back(item);
    int ci = data.size() - 1;
    while (ci > 0) {
      int pi = (ci - 1) / 2;
      if (data[ci] <= data[pi]) break;
      T tmp = data[ci];
      data[ci] = data[pi];
      data[pi] = tmp;
      ci = pi;
    }
  }

  T Dequeue() {
    if (data.size() == 0) {
      throw "queue is empty";
    }
    int li = data.size() - 1;
    T frontItem = data[0];
    data[0] = data[li];
    data.pop_back();

    --li;
    int pi = 0;

    while (true) {
      int ci = pi * 2 + 1;
      if (ci > li) break;
      int rc = ci + 1;
      if (rc <= li && data[rc] < data[ci]) ci = rc;
      if (data[pi] >= data[ci]) break;
      T tmp = data[pi];
      data[pi] = data[ci];
      data[ci] = tmp;
      pi = ci;
    }
    return frontItem;
  }

  T Peek() {
    if (data.size() == 0) {
      throw "queue is empty";
    }
    T frontItem = data[0];
    return frontItem;
  }

  int Count() { return data.size(); }
};
}  // namespace BinHeap
