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
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

int main(){
	
	std::stack<std::string> family;
	family.push("Hakan");
	family.push("Yigit");
	family.push("Melih");
	
	int size=family.size();
	
	if(!family.empty()){
		for(int i=0;i<size;i++){
			std::cout << family.top() << "\n";
			family.pop();
		}
	}
	
	std::cout << "\n";
	
	std::queue<std::string> cast;
	cast.push("Einstein");
	cast.push("Golstein");
	cast.push("Rammstein");

	int size2=cast.size();
	
	if(!cast.empty()){
		for(int i=0;i<size2;i++){
			std::cout << cast.front() << "\n";
			cast.pop();
		}
	}
	
	std::cout << "\n";
	
	std::priority_queue<int> nums;
	nums.push(5);
	nums.push(8);
	nums.push(4);
	
	int size3=nums.size();
	
	if(!nums.empty()){
		for(int i=0;i<size3;i++){
			std::cout << nums.top() << "\n";
			nums.pop();
		}
	}
	
	std::cout << "\n";
	
	enum day{mon=1,tues,wed,thrs,fri,sat,sun
	};
	
	for(int i=mon;i<=sun;i++){
		std::cout << i << "\n";
	}
	
	return 0;
	
}
