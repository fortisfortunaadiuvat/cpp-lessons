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

std::mutex veclock;
std::vector<unsigned int>primevec;

void Findprimes(unsigned int start,unsigned int end){
	for(unsigned int x=start;x<=end;x+=2){
		for(unsigned y=2;y<x;y++){
			if((x%y)==0){
				break;
			}else if((y+1)==x){
				veclock.lock();
				primevec.push_back(x);
				veclock.unlock();
			}
		}
	}
}

void Findprimeswithhread(unsigned int start,unsigned int end,unsigned int numthreads){
	std::vector<std::thread> threadvec;
	unsigned int threadspread=end/numthreads;
	unsigned int newend=start+threadspread-1;
	
	for(unsigned int x=0;x<numthreads;x++){
		threadvec.emplace_back(Findprimes,start,newend);
		start += threadspread;
		newend += threadspread;
	}	
	
	for(auto& t:threadvec){
		t.join();
	}
}

int main(){
	
	int starttime=clock();
	Findprimeswithhread(1,100,3);
	int endtime=clock();
	
	for(auto i:primevec){
		std::cout << i << "\n" ;
	}
	
	std::cout << "Execution time: " << (endtime-starttime)/double(CLOCKS_PER_SEC) << "\n";
	
	return 0;
	
}
