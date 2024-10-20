#include <gtest/gtest.h>
#include <calc/calc.hpp>

TEST(CalcTest, SumAddsTwoInts) {
  EXPECT_EQ(4, Calc::Sum(2, 2));
}

TEST(CalcTest, MultiplyMultipliesTwoInts) {
  EXPECT_EQ(12, Calc::Multiply(3, 4));
}
