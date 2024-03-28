#include "gtest/gtest.h"
#include "collision.hpp"

TEST(trianglesCollision, noCollision1){
    vec2 p11(100, 300);
    vec2 p12(100, 500);
    vec2 p13(300, 400);

    vec2 p21(600, 300);
    vec2 p22(600, 500);
    vec2 p23(800, 400);

    triangle triangle1;
    triangle1.points = {p11, p12, p13};

    triangle triangle2;
    triangle2.points = {p21, p22, p23};

    EXPECT_FALSE(isColliding(triangle1, triangle2));
}

TEST(trianglesCollision, Collision1){
    vec2 p11(-8, 1);
    vec2 p12(-4, 1);
    vec2 p13(-6, 4);

    vec2 p21(-6, 2);
    vec2 p22(-3, 2);
    vec2 p23(-3, 5);

    triangle triangle1;
    triangle1.points = {p11, p12, p13};

    triangle triangle2;
    triangle2.points = {p21, p22, p23};

    EXPECT_TRUE(isColliding(triangle1, triangle2));
}

TEST(trianglesCollision, noCollisio2n){
    vec2 p11(-9, -1);
    vec2 p12(-11, -2);
    vec2 p13(-8, -4);

    vec2 p21(-13, -6);
    vec2 p22(-12, -10);
    vec2 p23(-8, -11);

    triangle triangle1;
    triangle1.points = {p11, p12, p13};

    triangle triangle2;
    triangle2.points = {p21, p22, p23};

    EXPECT_FALSE(isColliding(triangle1, triangle2));
}

TEST(trianglesCollision, smallInsideBigger){
    vec2 p11(-4, -4);
    p11.x = -4;
    p11.y = -4;
    vec2 p12(7, -4);
    p12.x = 7;
    p12.y = -4;
    vec2 p13;
    p13.x = 1;
    p13.y = 5;

    vec2 p21(-1, -2);
    vec2 p22(4, -2);
    vec2 p23(1, 2);

    triangle triangle1;
    triangle1.points = {p11, p12, p13};

    triangle triangle2;
    triangle2.points = {p21, p22, p23};

    EXPECT_TRUE(isColliding(triangle1, triangle2));
}
