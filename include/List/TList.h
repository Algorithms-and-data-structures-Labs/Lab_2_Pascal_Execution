#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

namespace ListLib {
template <typename T>
struct Node {
  T value;
  std::vector<Node<T>*> next;
  int lvl;

  Node(const T& val, int l) : value(val), lvl(l) { next.resize(l); }
};

template <typename T>
class SkipList {
 public:
  SkipList(int maxHeight) : maxHeight(maxHeight), Empty(true) {
    srand(time(nullptr));
    head = new Node<T>(T(), maxHeight);  // Head node with maximum level
  }

  ~SkipList() {
    Node<T>* current = head;
    while (current != nullptr) {
      Node<T>* next = current->next[0];
      delete current;
      current = next;
    }
  }

  void insert(const T& value) {
    std::vector<Node<T>*> update(maxHeight, nullptr);
    Node<T>* current = head;

    for (int i = maxHeight - 1; i >= 0; --i) {
      while (current->next[i] != nullptr && current->next[i]->value < value)
        current = current->next[i];
      update[i] = current;
    }

    current = current->next[0];

    if (current == nullptr || current->value != value) {
      int level = randomlvl();
      if (level > maxHeight) {
        for (int i = maxHeight; i < level; ++i) update[i] = head;
        maxHeight = level;
      }
      Node<T>* newNode = new Node<T>(value, level);
      for (int i = 0; i < level; ++i) {
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
      }
    }
  }

  void remove(const T& value) {
    std::vector<Node<T>*> update(maxHeight, nullptr);
    Node<T>* current = head;

    for (int i = maxHeight - 1; i >= 0; --i) {
      while (current->next[i] != nullptr && current->next[i]->value < value)
        current = current->next[i];
      update[i] = current;
    }

    current = current->next[0];

    if (current != nullptr && current->value == value) {
      for (int i = 0; i < maxHeight; ++i) {
        if (update[i]->next[i] != current) break;
        update[i]->next[i] = current->next[i];
      }
      delete current;
      while (maxHeight > 1 && head->next[maxHeight - 1] == nullptr) --maxHeight;
      if (head->next[0] == nullptr) Empty = true;
    }
  }

  bool find(const T& value) const {
    Node<T>* current = head;

    for (int i = maxHeight - 1; i >= 0; --i) {
      while (current->next[i] != nullptr && current->next[i]->value < value)
        current = current->next[i];
    }

    current = current->next[0];

    return current != nullptr && current->value == value;
  }

  void print() const {
    Node<T>* current = head->next[0];
    while (current != nullptr) {
      std::cout << current->value << " ";
      current = current->next[0];
    }
    std::cout << std::endl;
  }

 private:
  int maxHeight;
  Node<T>* head;
  bool Empty;

  int randomlvl() {
    int level = 1;
    while (rand() % 2 == 0 && level < maxHeight) ++level;
    return level;
  }
};
}  // namespace ListLib
