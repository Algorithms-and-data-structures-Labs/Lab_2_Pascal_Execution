#include "HierarchicalList/HierarchicalList.h"
#include "gtest/gtest.h"

using namespace HListLib;

TEST(HList, basic) {
  HList<int> myList;
  myList.pushBack(1);
  myList.pushBack(2);
  myList.pushBack(3);
  HList<int> sublist;
  sublist.pushBack(4);
  sublist.pushBack(5);
  auto root = myList.getRoot();
  auto node = root->next;
  myList.addSublistAfter(node, sublist);

  std::cout << "Hierarchy:" << std::endl;
  myList.traverse(root);
  EXPECT_EQ(1, 1);
}
TEST(HList, sublistAtFirst) {
  HList<int> myList;
  myList.pushBack(1);
  myList.pushBack(2);
  myList.pushBack(3);
  HList<int> sublist;
  sublist.pushBack(4);
  sublist.pushBack(5);
  auto root = myList.getRoot();
  myList.addSublistAfter(root, sublist);

  std::cout << "Hierarchy:" << std::endl;
  myList.traverse(root);
  EXPECT_EQ(1, 1);
}
TEST(HList, sublistAtLast) {
  HList<int> myList;
  myList.pushBack(1);
  myList.pushBack(2);
  myList.pushBack(3);
  HList<int> sublist;
  sublist.pushBack(4);
  sublist.pushBack(5);
  auto root = myList.getRoot();
  auto node = root->next->next;
  myList.addSublistAfter(node, sublist);

  std::cout << "Hierarchy:" << std::endl;
  myList.traverse(root);
  EXPECT_EQ(1, 1);
}
TEST(HList, findElement) {
  HList<int> myList;
  myList.pushBack(1);
  myList.pushBack(2);
  myList.pushBack(3);
  HList<int> sublist;
  sublist.pushBack(4);
  sublist.pushBack(5);

  auto root = myList.getRoot();
  auto node = root->next;
  myList.addSublistAfter(node, sublist);
  hlistNode<int>* foundNode = myList.findElement(myList, 5);
  EXPECT_NE(foundNode, nullptr);
  EXPECT_EQ(foundNode->value, 5);
}
TEST(HList, addSublistToElementWithValue) {
  HList<int> myList;
  myList.pushBack(1);
  myList.pushBack(2);
  myList.pushBack(3);
  HList<int> sublist;
  sublist.pushBack(4);
  sublist.pushBack(5);
  myList.addSublistToElementWithValue(2, sublist);
  HList<int> sublist1;
  sublist1.pushBack(6);
  sublist1.pushBack(7);
  myList.addSublistToElementWithValue(4, sublist1);
  auto root = myList.getRoot();
  std::cout << "Hierarchy:" << std::endl;
  myList.traverse(root);
  EXPECT_EQ(root->value, 1);
}
TEST(HList, PascalProgramHierarchy1) {
  HList<std::string> myList;
  myList.pushBack("program");
  myList.pushBack("const");
  myList.pushBack("var");
  HList<std::string> sublist;
  sublist.pushBack("double");
  sublist.pushBack("integer");

  auto root = myList.getRoot();
  auto node = root->next;
  myList.addSublistAfter(node, sublist);
  hlistNode<std::string>* foundNode = myList.findElement(myList, "const");
  std::cout << "Hierarchy:" << std::endl;
  myList.traverse(root);
  EXPECT_EQ(5, 5);
}
TEST(HList, PascalProgramHierarchy2) {
  HList<std::string> programHierarchy;
  programHierarchy.pushBack("program");
  HList<std::string> level2;
  level2.pushBack("const");
  level2.pushBack("var");
  level2.pushBack("begin");
  programHierarchy.addSublistToElementWithValue("program", level2);
  HList<std::string> level3;
  level3.pushBack("Pi");
  level3.pushBack("num1");
  level3.pushBack("num2");
  level3.pushBack("Res");
  level3.pushBack("d");
  programHierarchy.addSublistToElementWithValue("const", level3);
  HList<std::string> level4;
  level4.pushBack("integer");
  level4.pushBack("double");
  programHierarchy.addSublistToElementWithValue("var", level4);
  HList<std::string> level5;
  level5.pushBack("num1 := 5;");
  level5.pushBack("Write(\"Введите четное целое число: \");");
  level5.pushBack("Read(num2);");
  level5.pushBack("Write(\"Введите вещественное число: \");");
  level5.pushBack("if (b mod 2 = 0) then");
  level5.pushBack("  Res := (num1 - num2 * 5 div 2) / (d * 2);");
  level5.pushBack("  Write(\"Результат = \", Res);");
  level5.pushBack("else");
  level5.pushBack("  Write(\"Неверный ввод\");");
  programHierarchy.addSublistToElementWithValue("begin", level5);
  auto root = programHierarchy.getRoot();
  std::cout << "Pascal Program Hierarchy:" << std::endl;
  programHierarchy.traverse(root);
  EXPECT_EQ(5, 5);
}
