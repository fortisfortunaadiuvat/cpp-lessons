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

template <typename T>

T Add(T val1,T val2){
	return val1+val2;
}

template <typename T>

T Max(T val1,T val2){
	return (val1<val2)?val2:val1;
}

int main(){
	
	std::cout << Add(5,6) << "\n";
	std::cout << Max(5,6) << "\n";
	
	return 0;
	
}
