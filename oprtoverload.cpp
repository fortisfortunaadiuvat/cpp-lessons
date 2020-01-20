#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>

class Box{
	public:
		double length,width,breadth;
		std::string boxstring;
		Box(){
			length=1,width=1,breadth=0;
		}
		Box(double l,double w,double b){
			length=l,width=w,breadth=b;
		}
		Box& operator ++ (){
			length++;
			width++;
			breadth++;
			return *this;
		}
		operator const char*(){
			std::ostringstream boxstream;
			boxstream << "Box: " <<
				length << "," <<
				width << "," <<
				breadth;
			boxstring=boxstream.str();
			return boxstring.c_str();
		}
		Box operator + (const Box& box2){
			Box boxsum;
			boxsum.length=length+box2.length;
			boxsum.width=width+box2.width;
			boxsum.breadth=breadth+box2.breadth;
			return boxsum;
		}
		double operator [] (int x){
			if(x==0){
				return length;
			}else if(x==1){
				return width;
			}else if(x==2){
				return breadth;
			}else{
				return 0;
			}
		}
		bool operator == (const Box& box2){
			return ((length=box2.length)&&
					(width=box2.width)&&
					(breadth=box2.breadth));
		}
		bool operator < (const Box& box2){
			double thissize=length+width+breadth;
			double box2size=box2.length+box2.width+box2.breadth;
			if(thissize<box2size){
				return true;
			}else {
				return false;
			}
		}
		bool operator > (const Box& box2){
			double thissize=length+width+breadth;
			double box2size=box2.length+box2.width+box2.breadth;
			if(thissize>box2size){
				return true;
			}else {
				return false;
			}
		}
		void operator =(const Box& copyBox){
			length=copyBox.length;
			width=copyBox.width;
			breadth=copyBox.breadth;
		}
	};

int main(){
	
	Box box(10,10,10);
	++box;
	std::cout << box << "\n";
	Box box2(5,5,5);
	std::cout << box+box2 << "\n";
	std::cout << std::boolalpha;
	std::cout << "are boxes equal? " << (box==box2) << "\n";
	
	box=box2;
	std::cout << box << "\n";
	
	return 0;
	
}
