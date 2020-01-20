#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
#include <functional>
#include <sstream>
#include <iterator>

template <typename V,typename U,typename T>

class Person{
	public:
		U height;
		T weight;
		static int numofPeople;
		Person(V n,U h,T w){
			name=n;
			height=h;
			weight=w;
			numofPeople++;
		}
		void GetData(){
			std::cout << "name is: " << name << "\n"
						"height is: " << height << "\n"
						"weight is: " << weight << "\n";
		}
		/*double GetNumofPerson(){
			return numofPeople;
		}*/
	private:
		V name;
};

template <typename V,typename U,typename T> int Person<V,U,T>::numofPeople;

int main(){
	
	Person<std::string,double,int> mikeTyson("Mike Tyson",5.85,111);
	mikeTyson.GetData();
	std::cout << "number of people: "<< mikeTyson.numofPeople << "\n";
	Person<std::string,double,int> muhammedAli("Muhammed Ali",5.95,121);
	muhammedAli.GetData();
	std::cout << "number of people: "<< muhammedAli.numofPeople << "\n";
	
	return 0;
	
}
