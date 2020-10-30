// Jeromy Schultz and Noah Ernst
// se3800date_ernstn_schultzjf
// 2020-10-30

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

TEST(DateTest, DaysBetweenDates){
  Date date1 = Date(1,1,2020);
  Date date2 = Date(1,1,2021);
  //should be 366 days because of leap year
  EXPECT_EQ(366, diffBetweenDates(date1, date2));
  Date date3 = Date(1,1,2021);
  Date date4 = Date(1,1,2022);
  EXPECT_EQ(365, diffBetweenDates(date3, date4));
  EXPECT_EQ(0, diffBetweenDates(date3, date2));

}


TEST(DateTest, ValidateDate) {
  ASSERT_TRUE(validateDate("0000-01-01"));
  ASSERT_TRUE(validateDate("9999-12-12"));
  ASSERT_TRUE(validateDate("2020-02-29"));
  ASSERT_FALSE(validateDate("0-0-0"));
  ASSERT_FALSE(validateDate("2020-1-1"));
  ASSERT_FALSE(validateDate("2020-2-30"));
  ASSERT_FALSE(validateDate("2021-2-29"));
}

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
