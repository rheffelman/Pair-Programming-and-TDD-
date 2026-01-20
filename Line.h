#pragma once
#include "Point.h"
#include <string>
#include <cmath>
#include <format>

class Line {
public:

    Line(Point initial_a, Point initial_b);
    double getLength();
    double getSlope();
    bool onLine(Point p);
    Point getMidpoint();
    void extendLine(double amt);
    string to_string();
    
private:

    Point a;
    Point b;
};