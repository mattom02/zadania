#include "collision.hpp"

double dot(const vec2 &a, const vec2 &b){
    return (a.x * b.x) + (a.y * b.y);
}

std::array<vec2, 3> calculateVectors(const vec2 &p, const vec2 &a, const vec2 &b, const vec2 &c){
    vec2 v0(c.x - a.x, c.y - a.y);
    vec2 v1(b.x - a.x, b.y - a.y);
    vec2 v2(p.x - a.x, p.y - a.y);
    std::array<vec2, 3> array = {v0, v1, v2};
    return array;
}

double calculateU(const vec2 &v0, const vec2 &v1, const vec2 &v2, double denominator){
    return ((dot(v1,v1) * dot(v2, v0)) - (dot(v1, v0) * dot(v2, v1))) / denominator;
}

double calculateV(const vec2 &v0, const vec2 &v1, const vec2 &v2, double denominator){
    return ((dot(v0,v0) * dot(v2, v1)) - (dot(v0, v1) * dot(v2, v0))) / denominator;
}

double calculateDenominator(const vec2 &v0, const vec2 &v1, const vec2 &v2){
    return (dot(v0, v0) * dot(v1, v1)) - (dot(v0,v1) * dot(v1, v0));
}

bool checkIfPointIsColliding(const triangle &Triangle, const vec2 &point){
    std::array<vec2, 3> vectors = calculateVectors(point, Triangle.points[0], Triangle.points[1], Triangle.points[2]);
    double denominator = calculateDenominator(vectors[0], vectors[1], vectors[2]);
    double u = calculateU(vectors[0], vectors[1], vectors[2], denominator);
    double v = calculateV(vectors[0], vectors[1], vectors[2], denominator);
    return (u >= 0) && (v >= 0) && (u + v < 1);
};

bool isColliding(const triangle &triangle1, const triangle &triangle2){
    return checkIfPointIsColliding(triangle1, triangle2.points[0])
           || checkIfPointIsColliding(triangle1, triangle2.points[1])
           || checkIfPointIsColliding(triangle1, triangle2.points[2])
           || checkIfPointIsColliding(triangle2, triangle1.points[0])
           || checkIfPointIsColliding(triangle2, triangle1.points[1])
           || checkIfPointIsColliding(triangle2, triangle1.points[2]);
}