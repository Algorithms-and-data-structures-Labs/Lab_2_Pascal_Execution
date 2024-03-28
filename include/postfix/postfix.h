#pragma once
#include <math.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

#include "stack/stack.h"

namespace PostfixLib {
class TArithmeticExpression {
 private:
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
}  // namespace PostfixLib
