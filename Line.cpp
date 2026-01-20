#include "Line.h"

Line::Line(Point initial_a, Point initial_b)
{
    a = initial_a;
    b = initial_b;
}
//--
double Line::getLength()
{
    double x = b.get_x() - a.get_x();
    double y = b.get_y() - a.get_y();
    double length = std::sqrt(x * x + y *y);
    return length;
}
//--
double Line::getSlope()
{
    double deltaX = b.get_x() - a.get_x();
    double deltaY = b.get_y() - a.get_y();

    if (deltaX == 0.0) // vertical line
    {
        printf("slope is undefined\n");
        return std::numeric_limits<double>::max();
    }
    return deltaY / deltaX;
}
//--
bool Line::onLine(Point p)
{
    double y_intercept = a.get_y() - getSlope() * a.get_x();
    double formula = getSlope() * p.get_x() + y_intercept;
    return (p.get_y() == formula);
}
//--
Point Line::getMidpoint()
{
    double x_val = (a.get_x() + b.get_x()) / 2;
    double y_val = (a.get_y() + b.get_y()) / 2;
    Point midpoint(x_val, y_val);
    return midpoint;
}
//--
void Line::extendLine(double amt)
{
    double half = amt / 2.0;
    double delta_x = b.get_x() - a.get_x();
    double delta_y = b.get_y() - a.get_y();
    double len = getLength();
    double direction_x = delta_x / len;
    double direction_y = delta_y / len;

    a = Point(a.get_x() - direction_x * half, a.get_y() - direction_y * half);
    b = Point(b.get_x() + direction_x * half, b.get_y() + direction_y * half);
}
//--
string Line::to_string()
{
    // compile with -std=c++20
    return "Line- Point 1: [" + a.to_string() + "], Point 2: [" + b.to_string() + "], Length: " + std::format("{:.1f}", getLength()) + "\n"; 
}