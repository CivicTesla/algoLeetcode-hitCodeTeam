#include <limits.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <cstdlib>
#include <iostream>
#include <string>

//! 引入需要测试的函数方法
#include "math/swap.h"
#include "math/add_int.h"
//! 引入结束


using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;
using ::testing::Exactly;
using namespace testing;
using namespace std;


TEST(SWAP_TEST, SWAP_TWO_INT) {
    int val1 = 10;
    int val2 = 20;
    swap(val1, val2);
    EXPECT_EQ(20, val1);//* EXPECT_EQ()检验值是否相等
    EXPECT_EQ(10, val2);
}
TEST(TestAddInt, test_add_int_1) {
  int res = add_int(10, 24);
  EXPECT_EQ(res, 34);
}