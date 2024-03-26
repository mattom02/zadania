#pragma once
#include <array>

struct vec2{
    vec2(float X, float Y){ x = X; y = Y;}

    vec2() = default;

    float x, y;
};

struct triangle{
    std::array<vec2, 3> points;
};

double dot(const vec2 &a, const vec2 &b);

std::array<vec2, 3> calculateVectors(const vec2 &p, const vec2 &a, const vec2 &b, const vec2 &c);

double calculateU(const vec2 &v0, const vec2 &v1, const vec2 &v2, double denominator);

double calculateV(const vec2 &v0, const vec2 &v1, const vec2 &v2, double denominator);

double calculateDenominator(const vec2 &v0, const vec2 &v1, const vec2 &v2);

bool checkIfPointIsColliding(const triangle &Triangle, const vec2 &point);

bool isColliding(const triangle &triangle1, const triangle &triangle2);