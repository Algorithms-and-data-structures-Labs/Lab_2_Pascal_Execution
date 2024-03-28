#include <string>

#include "gtest/gtest.h"
#include "postfix/postfix.h"

using namespace PostfixLib;

TEST(Postfix, can_create_calculator) {
  ASSERT_NO_THROW(TArithmeticExpression c("((12+(2-5+3+1))"));
}

TEST(Postfix, can_GetInfix_with_equal_count_brakets) {
  TArithmeticExpression TCR("((12+(2-5+3+1))");
  ASSERT_NO_THROW(TCR.GetInfix());
}

TEST(Postfix, can_Set_void_TCalculator) {
  TArithmeticExpression TCR("((12+(2-5+3+1))");
  ASSERT_NO_THROW(TCR.ConvertToPostfix());
}

TEST(Postfix, right_postfix_SetInfix) {
  TArithmeticExpression TCR("((12+(2-5+3+1))");
  TCR.ConvertToPostfix();
  ASSERT_NO_THROW(TCR.GetPostfix());
}
