#include "Point.h"
#include <cmath>
#include <format>

Point::Point(double initial_x, double initial_y)
{   
    x = initial_x;
    y = initial_y;
}
//--
Point::Point()
{
    x = 0;
    y = 0;
}
//--
double Point::get_x()
{
    return x;
}
//--
double Point::get_y()
{
    return y;
}
//--
string Point::to_string()
{
    // compile with -std=c++20
    return std::format("x: {:.1f}, y: {:.1f}", x, y);
}
