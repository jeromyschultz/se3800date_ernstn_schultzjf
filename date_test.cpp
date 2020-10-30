#include "date.h"
#include "datecalc.h"
#include <gtest/gtest.h>

TEST(DateTest, NormalDay) {
   Date date1 = Date(30,10,2020);
   Date date2 = Date(28,9,2020);
   Date date3 = Date(10,6,2014);
   EXPECT_EQ(5, determineDayOfWeek(date1));
   EXPECT_EQ(2, determineDayOfWeek(date3));
   EXPECT_EQ(1, determineDayOfWeek(date2));

}

TEST(DateTest, LeapYears){
  Date date1 = Date(29,2,2020);
  Date date2 = Date(29,2,2016);
  Date date3 = Date(29,2,2012);
  EXPECT_EQ(6, determineDayOfWeek(date1));
  EXPECT_EQ(3, determineDayOfWeek(date3));
  EXPECT_EQ(1, determineDayOfWeek(date2));

}
//
// TEST(CubeTest, NegativeNumbers) {
//    EXPECT_EQ(-15625, cube(-25));
// }
//
// TEST(CubeTest, OverflowNumbers){
//   EXPECT_EQ(0, cube(1291));
//   EXPECT_EQ(2146689000, cube(1290));
// }

TEST(DateTest, ValidateDate) {
  ASSERT_TRUE(validateDate("0-1-1"));
  ASSERT_TRUE(validateDate("9999-12-12"));
  ASSERT_TRUE(validateDate("2020-10"));
}

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
