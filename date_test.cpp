#include "date.h"
#include "datecalc.h"
#include <gtest/gtest.h>

TEST(DateTest, NaturalNumbers) {

}

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
