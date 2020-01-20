#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <functional>
#include <iterator>
#include "Animal.h"

int main(){
	Animal spot=Animal();
	spot.name="spot";
	
	std::cout << "Animal name is: " << spot.name << "\n";	
	
	
	return 0;
	
}
