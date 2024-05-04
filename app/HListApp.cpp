#include <iostream>

#include "HierarchicalList.h"

using namespace std;
using namespace HListLib;

int main() {

  HList<int> list;
  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);
  list.pushBack(4);
  list.pushBack(5);

  HList<int> sublist;
  sublist.pushBack(6);
  sublist.pushBack(7);
  sublist.pushBack(8);
  list.addSublistToElementWithValue(
      3, sublist);

  cout << "Main List:" << endl;
  list.traverse(list.getRoot());

  hlistNode<int>* nodeToRemove = list.findElement(list, 2);
  list.remove(nodeToRemove);

  cout << "\nMain List after removing 2 elem:" << endl;
  list.traverse(list.getRoot());

  int searchValue = 4;
  hlistNode<int>* foundNode = list.findElement(list, searchValue);
  if (foundNode) {
    cout << "\nelem is found -  " << searchValue << endl;
  } else {
    cout << "\nelem " << searchValue << " not found" << endl;
  }

  list.clear();
  cout << "\nmain list after cleaning:" << endl;
  list.traverse(list.getRoot());

  return 0;
}