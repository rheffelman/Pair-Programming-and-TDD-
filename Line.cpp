#include "Line.h"

Line::Line(Point initial_a, Point initial_b)
{
    a = initial_a;
    b = initial_b;
}
double Line::getLength()
{
    double x = b.get_x() - a.get_x();
    double y = b.get_y() - a.get_y();
    double length = std::sqrt(x * x + y *y);
    return length;
}
double Line::getSlope() {
    double deltaX = b.get_x() - a.get_x();
    double deltaY = b.get_y() - a.get_y();
    if (deltaX == 0.0) {
        printf("deltaX is 0\n");
    }
    return deltaY / deltaX;
}

bool Line::onLine(Point p) {
    double y_int = a.get_y() - getSlope() * a.get_x();
    double formula = getSlope() * p.get_x() + y_int;
    return p.get_y() == formula;
}
Point Line::getMidpoint() {
    double x_val = (a.get_x() + b.get_x()) / 2;
    double y_val = (a.get_y() + b.get_y()) / 2;
    Point midpoint(x_val, y_val);
    return midpoint;
}
void Line::extendLine(double amt)
{
    double half = amt / 2.0;

    double dx = b.get_x() - a.get_x();
    double dy = b.get_y() - a.get_y();
    double len = std::sqrt(dx*dx + dy*dy);

    if (len == 0.0) {
        return;
    }

    double ux = dx / len;
    double uy = dy / len;

    a = Point(a.get_x() - ux * half, a.get_y() - uy * half);
    b = Point(b.get_x() + ux * half, b.get_y() + uy * half);
}
string Line::to_string()
{
    return "Line- Point 1: [" + a.to_string() + "], Point 2: [" + b.to_string() + "], Length: " + std::format("{:.1f}", getLength()) + "\n"; 
}