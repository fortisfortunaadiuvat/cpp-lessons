#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <functional>

void is_odd(std::vector<int> list){
	for(int i=0;i<list.size();i++){
		if(list[i]%2!=0){
			std::cout << list[i] << "\t";
		}
	}
}

int main(){
	
	int N;
	std::cout << "Enter number of items: ";
	std::cin >> N;
	std::vector<int> ListofNumb(N);
	srand(time(NULL));
	
	for(int i=0;i<ListofNumb.size();i++){
		ListofNumb[i]=rand()%99;
	}
	
	for(int i=0;i<ListofNumb.size();i++){
		std::cout << ListofNumb[i] << "\t"; 
	}
	
	std::cout << "\n";
	
	is_odd(ListofNumb); 
	
	return 0;
	
}
