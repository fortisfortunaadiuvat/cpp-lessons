#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>

class Shape{
	protected:
		double height,width;
	public:
		Shape(double length){
			height=length;
			width=length;
		}
		Shape(double h,double w){
			height=h;
			width=w;
		}
	
	virtual double Area(){
		return height*width;
	}
};

struct Circle:public Shape{
	Circle(double w):Shape(w){
		
	}
	double Area(){
		return 3.14159*std::pow((width/2),2);
	}
};

void ShowArea(Shape& shape){
	std::cout << "Area: " << shape.Area() << "\n";
}

int main(){

	Shape square(10,10);
	Circle circle(10);
	ShowArea(square);
	ShowArea(circle);
	
	return 0;
	
}
