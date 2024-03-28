#include "gtest/gtest.h"
#include "Functions.hpp"

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

TEST(buttonPress, notPressed1){
    sf::Vector2i vector(10, 10);
    bool buttonPressed = isButtonPressed(vector, 535, 465, 660, 590);
    EXPECT_FALSE(buttonPressed);
}

TEST(buttonPress, Pressed1){
    sf::Vector2i vector(500, 630);
    bool buttonPressed = isButtonPressed(vector, 535, 465, 660, 590);
    EXPECT_TRUE(buttonPressed);
}

TEST(buttonPress, notPressed2){
    sf::Vector2i vector(21, 15);
    bool buttonPressed = isButtonPressed(vector, 20, 10, 20, 10);
    EXPECT_FALSE(buttonPressed);
}

TEST(buttonPress, Pressed2){
    sf::Vector2i vector(69, 49);
    bool buttonPressed = isButtonPressed(vector, 70, 30, 50, 30);
    EXPECT_TRUE(buttonPressed);
}