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

int main(){
	
	std::vector<int> num={1,2,3,4,5};
	std::vector<int>::iterator itr;
	
	for(itr=num.begin();itr<num.end();itr++){
		std::cout << *itr << "\n";
	}
	
	std::vector<int>::iterator itr2=num.begin();
	advance(itr2,2);
	
	std::cout << *itr2 << "\n";
	
	auto itr3=next(itr2,1);
	
	std::cout << *itr3 << "\n";
	
	auto itr4=prev(itr2,1);
	
	std::cout << *itr4 << "\n";
	
	std::vector<int> num2={1,4,5,6};
	std::vector<int> num3={2,3};
	auto itr5=num2.begin();
	advance(itr5,1);
	copy(num3.begin(),num3.end(),inserter(num2,itr5));
	
	for(int &i:num2){
		std::cout << i << "\n";
	}
	
	return 0;
	
}
