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

double accountbalance=100;

std::mutex accountlock;

void Getmoney(int id,double withdrawacct){
	std::lock_guard<std::mutex> lock(accountlock);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << id << " tries to withdraw $ " <<
				withdrawacct << "on " <<
				Gettime() << "\n";
				
	if((accountbalance-withdrawacct)>=0){
		accountbalance -= withdrawacct;
		std::cout << "New account balance is: " <<
				accountbalance << "\n";	
	}else{
		std::cout << "Current balance is: $" <<
					accountbalance << "\n";
	}
}

int main(){
	
	std::thread threads[10];
	
	for(int i=0;i<10;i++){
		threads[i]=std::thread(Getmoney,i,15);
	}
	
	for(int i=0;i<10;i++){
		threads[i].join();
	}
	
	return 0;
	
}
