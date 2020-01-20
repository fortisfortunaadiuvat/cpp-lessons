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

void Executethread(int id){
	auto nowtime=std::chrono::system_clock::now();
	std::time_t sleeptime=std::chrono::system_clock::to_time_t(nowtime);
	tm mylocaltime=*localtime(&sleeptime);
	
	std::cout << "Thread " << id << " Sleep time: " << 
				std::ctime(&sleeptime) << "\n";

	std::cout << "Month: " << 
			mylocaltime.tm_mon+1 << "\n";
	std::cout << "Day: " << 
			mylocaltime.tm_mday << "\n";
	std::cout << "Year: " << 
			mylocaltime.tm_year + 1900 << "\n";
	std::cout << "Hour: " << 
			mylocaltime.tm_hour<< "\n";
	std::cout << "Min: " << 
			mylocaltime.tm_min<< "\n";
	std::cout << ": " << 
			mylocaltime.tm_sec << "\n\n";
			
	std::this_thread::sleep_for(std::chrono::seconds(Getnumber(3)));
	nowtime = std::chrono::system_clock::now();
	sleeptime=std::chrono::system_clock::to_time_t(nowtime);
	
	std::cout << "Thread " << id << " Awake time: " << 
				std::ctime(&sleeptime) << "\n";
}



int main(){
	std::thread th1(Executethread,1);
	th1.join();
	std::thread th2(Executethread,2);
	th2.join();
	
	return 0;
	
}
