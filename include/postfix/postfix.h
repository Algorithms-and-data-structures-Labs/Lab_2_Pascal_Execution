#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "stack/stack.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace Stack_Lib;

namespace Postfix_Lib {
class TArithmeticExpression {
  std::string infix;
  std::string postfix;
  std::vector<int> kolcifr;

 public:
  TArithmeticExpression(std::string infx);
  std::string GetInfix() const { return infix; }
  std::string GetPostfix() const { return postfix; }
  void ConvertToPostfix();
  int Priority(const char prior);
  double Calculate();
};

int TArithmeticExpression::Priority(const char prior) {
  switch (prior) {
    case '(':
      return 1;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    default:
      throw "Error not operation";
  }
}
TArithmeticExpression::TArithmeticExpression(std::string infx) {
  infix = infx;
  postfix = "";
  int count = 0;
  for (char c : infix)
    if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' ||
        c == '7' || c == '8' || c == '9' || c == '0' || c == '.')
      count++;
    else {
      if (count != 0) kolcifr.push_back(count);
      count = 0;
    }
  if (count != 0) kolcifr.push_back(count);
}

void TArithmeticExpression::ConvertToPostfix() {
  TStack<char> st(infix.length() * 3);
  std::vector<char> lexems;
  for (char c : infix) lexems.push_back(c);
  char stackItem;
  for (char item : lexems) {
    switch (item) {
      case '(':
        st.Push(item);
        break;
      case ')':
        stackItem = st.Get();
        while (stackItem != '(') {
          postfix += stackItem;
          stackItem = st.Get();
        }
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        while (!st.IsEmpty()) {
          stackItem = st.Get();
          if (Priority(item) <= Priority(stackItem))
            postfix += stackItem;
          else {
            st.Push(stackItem);
            break;
          }
        }
        st.Push(item);
        break;
      default:
        postfix += item;
    }
  }
  while (!st.IsEmpty()) {
    stackItem = st.Get();
    postfix += stackItem;
  }
}
double TArithmeticExpression::Calculate() {
  TStack<double> st(1000);
  double a, b;
  double foradd = 0;
  int count = 0;
  int indvector = 0;
  int i = 0;
  while (i < postfix.length()) {
    switch (postfix[i]) {
      case '+':
        a = st.Get();
        b = st.Get();
        st.Push(a + b);
        break;
      case '-':
        a = st.Get();
        b = st.Get();
        st.Push(b - a);
        break;
      case '*':
        a = st.Get();
        b = st.Get();
        st.Push(a * b);
        break;
      case '/':
        a = st.Get();
        b = st.Get();
        st.Push(b / a);
        break;
      default:
        char* perecod = new char[100];
        for (int j = 0; j < kolcifr[indvector]; j++)
          perecod[j] = postfix[i + j];

        foradd = atof(perecod);
        i += kolcifr[indvector] - 1;
        indvector++;
        st.Push(foradd);
    }
    i++;
  }
  return st.Get();
}
}
#endif