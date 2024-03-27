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
  TStack(const TStack<T>& stack);
  ~TStack();
  void Push(T a);
  T Get();
  T const TopView();
  int const GetSize();
  int const GetTop();
  bool const IsFull();
  bool const IsEmpty();
  void const printstack();
  TStack& operator=(const TStack<T>& stack);
  friend std::ostream& operator<<(std::ostream& ostr, const TStack<T>& A);
  friend std::istream& operator>>(std::istream& istr, TStack<T>& A);
};

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TStack<T>& A) {
  for (int i = 0; i < A.top; i++) {
    ostr << A.mas[i] << "\n";
    ostr << endl;
  }
  return ostr;
}

template <class T>
std::istream& operator>>(std::istream& istr, TStack<T>& A) {
  for (int i = 0; i < A.size; i++) {
    istr >> A.mas[i];
  }
  return istr;
}

template <class T>
void TStack<T>::Push(T a) {
  if (IsFull()) throw "StackFull";
  this->mas[top] = a;
  top++;
}

template <class T>
T TStack<T>::Get() {
  if (IsEmpty()) throw "StackEmpty";
  top--;
  return mas[top];
}

template <class T>
TStack<T>::TStack(int n) {
  if (n < 0)
    throw "Error size";
  else if (n == 0) {
    size = 0;
    top = 0;
  } else {
    size = n;
    mas = new T[n];
    top = 0;
  }
}

template <class T>
void const TStack<T>::printstack() {
  for (int i = top - 1; i >= 0; i--) std::cout << " " << mas[i];
}

template <class T>
TStack<T>::TStack(const TStack<T>& stack) {
  this.size = stack.size;
  T* mas = new T[this.size];
  for (int i = 0; i < this.size i++) mas[i] = stack.mas[i];
  this->top = stack.top;
}

template <class T>
TStack<T>::~TStack() {
  delete[] mas;
  top = 0;
  size = 0;
}

template <class T>
bool const TStack<T>::IsEmpty() {
  return (top == 0);
}

template <class T>
bool const TStack<T>::IsFull() {
  return (top >= size);
}

template <class T>
int const TStack<T>::GetSize() {
  return size;
}

template <class T>
int const TStack<T>::GetTop() {
  return top;
}

template <class T>
T const TStack<T>::TopView() {
  return mas[top];
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& a) {
  if (this != &a) {
    delete[] mas;
    top = a.top;
    size = a.size;
    mas = new T[size];
    for (int i = 0; i < size; i++) mas[i] = a.mas[i];
  }
  return *this;
}
}
#endif
