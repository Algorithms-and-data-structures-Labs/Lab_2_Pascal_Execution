#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace HListLib {
template <typename T>
struct hlistNode {
  hlistNode<T>* parent;
  hlistNode<T>* child;
  hlistNode<T>* next;
  hlistNode<T>* prev;
  hlistNode<T>* sublist;
  T value;

  hlistNode(const T& val)
      : parent(nullptr),
        child(nullptr),
        next(nullptr),
        prev(nullptr),
        sublist(nullptr),
        value(val) {}
};

template <typename T>
class HList {
 private:
  hlistNode<T>* root_;

 public:
  HList() : root_(nullptr) {}

  ~HList() { clear(); }

  void clear() {
    while (root_) {
      hlistNode<T>* next = root_->next;
      delete root_;
      root_ = next;
    }
  }

  void pushFront(const T& value) {
    hlistNode<T>* node = new hlistNode<T>(value);
    if (!root_) {
      root_ = node;
    } else {
      node->next = root_;
      root_->prev = node;
      root_ = node;
    }
  }

  void pushBack(const T& value) {
    hlistNode<T>* node = new hlistNode<T>(value);
    if (!root_) {
      root_ = node;
    } else {
      hlistNode<T>* current = root_;
      while (current->next) {
        current = current->next;
      }
      current->next = node;
      node->prev = current;
    }
  }

  void insertAfter(hlistNode<T>* node, const T& value) {
    if (!node) {
      throw std::runtime_error("Node is null");
    }
    hlistNode<T>* newNode = new hlistNode<T>(value);
    newNode->next = node->next;
    newNode->prev = node;
    node->next = newNode;
    if (newNode->next) {
      newNode->next->prev = newNode;
    }
  }

  void addSublistAfter(hlistNode<T>* node, HList<T>& sublist) {
    if (!node) {
      throw std::runtime_error("Node is null");
    }
    if (!sublist.root_) {
      return;
    }
    if (node->sublist) {
      throw std::runtime_error("Node already has a sublist");
    }
    node->sublist = sublist.root_;
    sublist.root_ = nullptr;
  }

  void remove(hlistNode<T>* node) {
    if (!node) {
      throw std::runtime_error("Node is null");
    }
    if (node->prev) {
      node->prev->next = node->next;
    } else {
      root_ = node->next;
    }
    if (node->next) {
      node->next->prev = node->prev;
    }
    deleteSublist(node->sublist);
    delete node;
  }

  void deleteSublist(hlistNode<T>* node) {
    if (!node) {
      return;
    }
    deleteSublist(node->next);
    deleteSublist(node->child);
    delete node;
  }

  hlistNode<T>* getRoot() { return root_; }

  void traverse(hlistNode<T>* node, int depth = 0) {
    while (node) {
      for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
      }
      std::cout << "|-- " << node->value << std::endl;
      if (node->sublist) {
        traverse(node->sublist, depth + 1);
      }
      node = node->next;
    }
  }

  hlistNode<T>* findElement(HList<T>& list, const T& value) {
    hlistNode<T>* root = list.getRoot();
    return findElementRecursive(root, value);
  }

  hlistNode<T>* findElementRecursive(hlistNode<T>* node, const T& value) {
    if (!node) return nullptr;
    if (node->value == value) return node;
    if (node->sublist) {
      hlistNode<T>* foundInSublist = findElementRecursive(node->sublist, value);
      if (foundInSublist) return foundInSublist;
    }
    return findElementRecursive(node->next, value);
  }

  void addSublistToElementWithValue(const T& value, HList<T>& sublist) {
    hlistNode<T>* node = findElement(*this, value);
    if (node) {
      addSublistAfter(node, sublist);
      sublist.root_ = nullptr;
    }
  }
};
}  // namespace HListLib
