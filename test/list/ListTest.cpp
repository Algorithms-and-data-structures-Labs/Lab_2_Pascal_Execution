#include "gtest/gtest.h"
#include "List/TList.h"

using namespace ListLib;

TEST(TList, can_find1) {
  SkipList<int> skipList(5);

  skipList.insert(1);
  skipList.insert(2);
  skipList.insert(3);
  skipList.insert(4);
  skipList.insert(5);
  skipList.print();
  skipList.remove(3);
  skipList.remove(4);
  skipList.print();
  EXPECT_TRUE(skipList.find(2));
  EXPECT_FALSE(skipList.find(3));
  EXPECT_FALSE(skipList.find(4));
  EXPECT_TRUE(skipList.find(1));
  EXPECT_TRUE(skipList.find(5));
}
TEST(TList, can_find2) {
  SkipList<int> skipList(5);

  skipList.insert(1);
  skipList.insert(2);
  skipList.insert(3);
  skipList.insert(4);
  skipList.insert(5);
  skipList.print();
  skipList.remove(3);
  skipList.print();
  EXPECT_TRUE(skipList.find(2));
  EXPECT_FALSE(skipList.find(3));
  EXPECT_TRUE(skipList.find(4));
  EXPECT_TRUE(skipList.find(1));
  EXPECT_TRUE(skipList.find(5));
}
TEST(TList, can_find3) {
  SkipList<int> skipList(5);

  skipList.insert(1);
  skipList.insert(2);
  skipList.insert(3);
  skipList.insert(4);
  skipList.insert(5);
  skipList.print();
  skipList.remove(3);
  skipList.remove(4);
  skipList.remove(5);
  skipList.print();
  EXPECT_TRUE(skipList.find(2));
  EXPECT_FALSE(skipList.find(3));
  EXPECT_FALSE(skipList.find(4));
  EXPECT_TRUE(skipList.find(1));
  EXPECT_FALSE(skipList.find(5));
}
TEST(TList, can_find4) {
  SkipList<int> skipList(5);
  skipList.insert(1);
  skipList.insert(2);
  skipList.insert(3);
  skipList.print();
  skipList.remove(3);
  skipList.print();
  EXPECT_TRUE(skipList.find(2));
  EXPECT_FALSE(skipList.find(3));
  EXPECT_TRUE(skipList.find(1));
}