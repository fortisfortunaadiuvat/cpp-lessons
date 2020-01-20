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
#include <mutex>
#include <thread>

int Getnumber(int max){
	srand(time(NULL));
	return rand()%max;
}

std::string Gettime(){
	auto nowtime=std::chrono::system_clock::now();
	std::time_t sleeptime=std::chrono::system_clock::to_time_t(nowtime);
	return std::ctime(&sleeptime);
}

void Findprimes(unsigned int start,unsigned int end,std::vector<unsigned int>&vec){
	for(unsigned int x=start;x<=end;x+=2){
		for(unsigned y=2;y<x;y++){
			if((x%y)==0){
				break;
			}else if((y+1)==x){
				vec.push_back(x);
			}
		}
	}
}

int main(){
	
	std::vector<unsigned int> primevec;
	int starttime=clock();
	Findprimes(1,100,primevec);
	
	for(auto i:primevec){
		std::cout << i << "\n";
	}
	
	int endtime=clock();
	std::cout << "Execution time: " << (endtime-starttime)/double(CLOCKS_PER_SEC) << "\n";
	
	return 0;
	
}
