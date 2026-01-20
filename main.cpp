#include <iostream>
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include <string>
#include <format>
#include "Point.h"
#include <cmath>
#include "Line.h"
using namespace std;

//--
TEST_CASE("Test Template")  
{ 
	REQUIRE(100 == 100); 

	Point p(1.0, 2.0);
	REQUIRE(p.get_x() == 1.0);
	REQUIRE(p.get_y() == 2.0);

	Point p2(1.1234, 2.0);
	REQUIRE(p2.get_x() == 1.1234);
	REQUIRE(p2.get_y() == 2.0);

	Point p3(0.0, 1.0);
	Point p4(1.0, 3.0);
	Point test(2.0, 5.0);
	Line l(p3, p4);

	//REQUIRE(l.getSlope() == -2.0);
	REQUIRE(l.onLine(test) == true);
	cout<< l.to_string();

	Point p5(0.0, 0.0);
	Point p6(0.0, 5.0);
	Line l2(p5, p6);
	cout<< l2.to_string();
	cout<<l2.getLength()<<endl;

	l2.extendLine(1);

	cout<< l2.to_string();
}