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
#include <memory>
#include <stdio.h>

int main(){
	
	int amttostore;
	std::cout << "How many num do you want to store: ";
	std::cin >> amttostore;
	
	std::unique_ptr<int[]> pNums(new int[amttostore]);
	
	if(pNums != NULL){
		int i=0;
		while(i<amttostore){
			std::cout << "Enter a number:"; 
			std::cin >> pNums[i];
			i++;
		}
	}
	
	std::cout << "You entered these number: \n";
	
	for(int i=0;i<amttostore;i++){
		std::cout << pNums[i] << "\t";
	}
	
	return 0;
	
}
