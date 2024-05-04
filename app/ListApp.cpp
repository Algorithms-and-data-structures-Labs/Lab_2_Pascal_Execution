#include <iostream>

#include "TList.h"

using namespace std;
using namespace ListLib;

int main() {
  SkipList<int> skipList(4);

  skipList.insert(10);
  skipList.insert(20);
  skipList.insert(30);
  skipList.insert(40);
  skipList.insert(50);

  cout << "SkipList after adding elems: ";
  skipList.print();

  int searchValue = 30;
  cout << "find elem " << searchValue << " ...."<<endl;
  if (skipList.find(searchValue)) {
    cout << "elem " << searchValue << " is found in skiplist." << endl;
  } else {
    cout << "elem " << searchValue << " is not found in skiplist." << endl;
  }

  searchValue = 15;
  cout << "find elem " << searchValue << " ...."<<endl;
  if (skipList.find(searchValue)) {
    cout << "elem " << searchValue << " is found in skiplist." << endl;
  } else {
    cout << "elem " << searchValue << " is not found in skiplist." << endl;
  }

  skipList.remove(30);

  cout << "SkipList after removing elem 30: ";
  skipList.print();

  return 0;
}