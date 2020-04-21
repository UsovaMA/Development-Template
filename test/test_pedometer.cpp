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

// =(( 
TEST(TestHelpFunctions, ResizeForData) {
  bool answer = false;
  Data *x, *y, *tmp;
  int i, j;
  y = 0;
  x = new Data[2];
  tmp = new Data[2];
  for (i = 0; i < 2; ++i) {
    x[i].num_of_steps = 41 + i;
    x[i].time_start = 200 + i;
    x[i].time_finish = 502 + i;
    for (j = 0; j < 3; ++j)
      x[i].date[j] = 2 + j + i;
  }
  cout << x[1].num_of_steps;
  for (i = 0; i < 2; ++i)
    tmp[i] = x[i];
  y = Resize(tmp, 2, 2);
  for (i = 0; i < 2; ++i) {
    if (x[i].time_start == y[i].time_start
      && x[i].time_finish == y[i].time_finish
      && x[i].num_of_steps == y[i].num_of_steps) {
      for (j = 0; j < 3; ++j) {
        if (x[i].date[j] == y[i].date[j]) {
          if (i == 1 && j == 2)
            answer = true;
        }
      }
    }
  }
  EXPECT_EQ(true, answer);
}

TEST(TestHelpFunctions, ResizeForInt) {
  bool answer = false;
  int *x, *y, *tmp, i;
  y = 0;
  x = new int[2];
  tmp = new int[2];
  x[0] = tmp[0] = 4;
  x[1] = tmp[1] = 8;
  y = Resize(tmp, 2, 2);
  for (i = 0; i < 2; ++i) {
    if (x[i] != y[i])
      break;
  }
  if (i == 2)
    answer = true;
  EXPECT_EQ(true, answer);
}

TEST(TestHelpFunctions, Min) {
  int x, y, res;
  x = 10;
  y = 5;
  res = y;
  EXPECT_EQ(res, min(x, y));
}

TEST(TestHelpFunctions, StringTimeToMin) {
  string time = "10:23";
  int res = 623;
  EXPECT_EQ(res, StringTimeToMin(time));
}
// =((
TEST(TestHelpFunctions, StringDateToIntArr) {
  string date = "21.04.20";
  bool answer = false;
  int arr[3], i;
  for (i = 0; i < 3; ++i)
    arr[i] = 0;
  StringDateToIntArr(date, arr);
  if (arr[0] == 21 && arr[1] == 4 && arr[2] == 20)
    answer = true;
  EXPECT_EQ(true, answer);
}

TEST(TestHelpFunctions, toInt) {
  string number = "2124";
  int res = 2124;
  EXPECT_EQ(res, toInt(number));
}