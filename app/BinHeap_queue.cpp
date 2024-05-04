#include <iostream>

#include "BinHeap.h"

using namespace std;
using namespace BinHeap;

int main() {
  PriorityQueue<int> pq;

  pq.Enqueue(1);
  cout << "Added element: 1" << endl;

  cout << "Size of pq is : " << pq.Count()
       << " and Peek Element is : " << pq.Peek() << endl;

  pq.Enqueue(10);
  cout << "Added element: 10" << endl;
  pq.Enqueue(-8);
  cout << "Added element: -8" << endl;

  cout << "Size of pq is : " << pq.Count()
       << " and Peek Element is : " << pq.Peek() << endl;

  pq.Dequeue();
  cout << "Removed element from queue" << endl;

  cout << "Size of pq is : " << pq.Count()
       << " and Peek Element is : " << pq.Peek() << endl;

  pq.Dequeue();
  cout << "Removed element from queue" << endl;

  cout << "Size of pq is : " << pq.Count()
       << " and Peek Element is : " << pq.Peek() << endl;

  pq.Enqueue(25);
  cout << "Added element: 25" << endl;

  cout << "Size of pq is : " << pq.Count()
       << " and Peek Element is : " << pq.Peek() << endl;

  return 0;
}
