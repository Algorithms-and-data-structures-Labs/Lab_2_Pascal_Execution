#ifndef __STACK_H__
#define __STACK_H__
#include <math.h>

#include <iostream>

namespace Stack_Lib {
template <class T>
class TStack {
 protected:
  int size;
  int top;
  T* mas;

 public:
  TStack(int n = 1);
  TStack(TStack<T>& stack);
  ~TStack();
  void Push(T a);
  T Get();
  T TopView();
  int GetSize();
  int GetTop();
  bool IsFull();
  bool IsEmpty();
  void printstack();
  TStack& operator=(const TStack<T>& stack);
  friend std::ostream& operator<<(std::ostream& ostr, const TStack<T>& A);
  friend std::istream& operator>>(std::istream& istr, TStack<T>& A);
};
}  // namespace Stack
#endif
