#include "date.h"
#include "datecalc.h"
#include <gtest/gtest.h>

TEST(DateTest, NormalDay) {
   Date date1 = Date(30,10,2020)
   EXPECT_EQ(5, determineDayOfWeek(date1));

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
//
// int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
// }
