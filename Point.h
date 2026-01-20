	#pragma once
    #include<string>
    using namespace std;
    
    class Point 
	{
    public:

        Point(double initial_x, double initial_y);
        Point();
        double get_x();
        double get_y();
        string to_string();

    private:
    
		double x;
		double y;

	};