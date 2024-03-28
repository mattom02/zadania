#include "gtest/gtest.h"
#include "change.hpp"

TEST(calculateChange, properChange){
    size_t totalValue = 14;
    std::array<std::size_t, 3> result = {2, 0, 1};
    EXPECT_EQ(calculateChange(3, totalValue), result);
}

TEST(calculateChange, properChange2){
    size_t totalValue = 10;
    std::array<std::size_t, 3> result = {1, 0, 1};
    EXPECT_EQ(calculateChange(4, totalValue), result);
}

TEST(calculateChange, properChange3){
    size_t totalValue = 30;
    std::array<std::size_t, 3> result = {4, 1, 0};
    EXPECT_EQ(calculateChange(8, totalValue), result);
}

TEST(calculateChange, properChange4){
    size_t totalValue = 10;
    std::array<std::size_t, 3> result = {0, 0, 0};
    EXPECT_EQ(calculateChange(10, totalValue), result);
}

TEST(calculateChange, valueReset){
    size_t totalValue = 20;
    calculateChange(10, totalValue);
    EXPECT_EQ(totalValue, 0);
}