#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <functional>

std::vector<char> GetHandTail(std::vector<char> posibleValues,
		int numberofgenerate){
		srand(time(NULL));
		std::vector<char> HandTailList;
		
		for(int i=0;i<numberofgenerate;++i){
			int randIndex=rand()%2;
			HandTailList.push_back(posibleValues[randIndex]);
		}
		
		return 	HandTailList;	
}

int GetNumberOfMatches(std::vector<char> list,char valuetofind){
	int numofmatches=0;
	
	for(auto c:list){
		if(c==valuetofind){
			numofmatches++;
		}
	}
	
	return numofmatches;
}

int main(){
	
	std::vector<char> posibleValues{'H','T'};
	std::vector<char> HandTailList=GetHandTail(posibleValues,100);
	
	std::cout << "Number of heads: " << 
				GetNumberOfMatches(HandTailList,'H') << "\n";
	
	std::cout << "Number of tails: " << 
				GetNumberOfMatches(HandTailList,'T') << "\n";
	
	return 0;
	
}
