#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <functional>

double Multiby2(double num){
	return num*2;
}

/*double doMath(std::function<double(double)>func,double num){
	return func(num);
}*/

double Multiby3(double num){
	return num*3;
}

int main(){
	
	auto times2=Multiby2;
	std::cout << times2(5) << "\n";
	std::vector<std::function<double(double)>> func2(2);
	func2[0]=Multiby2;
	func2[1]=Multiby3;
	
	for(int i=0;i<2;i++){
		std::cout << func2[i](10) << "\n";
	}
	
	return 0;
		
}
