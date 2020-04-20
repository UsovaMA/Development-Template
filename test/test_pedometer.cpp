#include <gtest/gtest.h>
#include "pedometer.h"


TEST(TestFunctions, AddCount) {
  Pedometer x;
  Pedometer res("12.12.12", "12:20", "15:20", 2000);
  x.addCounting("12.12.12","12:20", "15:20", 2000);
  EXPECT_EQ (x,res);
}

TEST(TestFunctions, GetInfoAboutCount_ThereIsInfo) {
  Pedometer x;
  Pedometer res("12.12.12", "12:20", "15:20", 2000);
  x = res.getInfo("12.12.12", "10:00", "16:00");
  EXPECT_EQ(x, res);
}

TEST(TestFunctions, GetInfoAboutCount_ThereIsNoInfo) {
  Pedometer res("12.12.12", "12:20", "15:20", 2000);
  ASSERT_ANY_THROW(res.getInfo("12.12.12", "16:00", "17:00"));
}

TEST(TestFunctions, FindAvarageCountPerMount_ThereIsInfo) {
  myPair result, res;
  Pedometer x("12.12.12", "12:20", "15:20", 2000);
  x.addCounting("12.12.12", "11:20", "12:00", 4000);
  res.first = 3000;
  res.second = 0;
  result = x.findAvarageOrMaxNumOfSteps("12.12", false, false);
  EXPECT_EQ(res, result);
}

TEST(TestFunctions, FindAvarageCountPerMount_ThereIsNoInfo) {
  Pedometer x("12.12.12", "12:20", "15:20", 2000);
  x.addCounting("12.12.12", "11:20", "12:00", 4000);
  ASSERT_ANY_THROW(x.findAvarageOrMaxNumOfSteps("12.13", false, false));
}

TEST(TestFunctions, FindAvarageCountForAllTime_ThereIsInfo) {
  myPair result, res;
  Pedometer x("12.12.12", "12:20", "15:20", 2000);
  x.addCounting("12.11.13", "11:20", "12:00", 4000);
  x.addCounting("11.10.15", "16:20", "17:30", 6000);
  res.first = 4000;
  res.second = 0;
  result = x.findAvarageOrMaxNumOfSteps("12.12", true, false);
  EXPECT_EQ(res, result);
}

TEST(TestFunctions, FindAvarageCountForAllTime_ThereIsNoInfo) {
  Pedometer x;
  ASSERT_ANY_THROW(x.findAvarageOrMaxNumOfSteps("12.12", true, false));
}

TEST(TestFunctions, FindMaxCountPerMount_ThereIsInfo) {
  myPair result, res;
  Pedometer x("12.12.12", "12:20", "15:20", 2000);
  x.addCounting("12.12.12", "11:20", "12:00", 4000);
  res.first = 4000;
  res.second = 1;
  result = x.findAvarageOrMaxNumOfSteps("12.12", false, true);
  EXPECT_EQ(res, result);
}

TEST(TestFunctions, FindMaxCountPerMount_ThereIsNoInfo) {
  Pedometer x("12.12.12", "12:20", "15:20", 2000);
  x.addCounting("12.12.12", "11:20", "12:00", 4000);
  ASSERT_ANY_THROW(x.findAvarageOrMaxNumOfSteps("12.13", false, true));
}

TEST(TestFunctions, FindMaxCountForAllTime_ThereIsInfo) {
  myPair result, res;
  Pedometer x("12.12.12", "12:20", "15:20", 2000);
  x.addCounting("12.11.13", "11:20", "12:00", 4000);
  x.addCounting("11.10.15", "16:20", "17:30", 6000);
  res.first = 6000;
  res.second = 2;
  result = x.findAvarageOrMaxNumOfSteps("12.12", true, true);
  EXPECT_EQ(res, result);
}

TEST(TestFunctions, FindMaxCountForAllTime_ThereIsNoInfo) {
  Pedometer x;
  ASSERT_ANY_THROW(x.findAvarageOrMaxNumOfSteps("12.12", true, true));
}

TEST(TestFunctions, FindStartDate_ThereIsInfo) {
  myPair result, res;
  Pedometer x("12.12.12", "12:20", "15:20", 2000);
  x.addCounting("12.11.13", "11:20", "12:00", 4000);
  x.addCounting("11.10.15", "16:20", "17:30", 6000);
  res.first = 6000;
  res.second = 2;
  result = x.findAvarageOrMaxNumOfSteps("12.12", true, true);
  EXPECT_EQ(res, result);
}

TEST(TestFunctions, ReadFromFile_ThereIsInfo) {
  string filePart1 = "C:/Users/Professional/Documents/MyTasksForGitHub/";
  string filePart2 =  "Class-Pedometer/build/app/Count's-history.txt";
  string file = filePart1 + filePart2;
  Pedometer res("12.12.12", "12:20", "14:30", 2000), x;
  x.readHistoryFromFile(file, false);
  EXPECT_EQ(x, res);
}

TEST(TestFunctions, ReadFromFile_IncorrectFileName) {
  Pedometer x;
  string file;
  file = "Count's-history.txt";  // Irony :)
  ASSERT_ANY_THROW(x.readHistoryFromFile(file, false));
}

