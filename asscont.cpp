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

int main(){
	
	std::set<int> set={1,2,5,3,4};
	std::cout << "Size: " << set.size() << "\n";
	
	if(!set.empty()){
		for(auto i:set){
			std::cout << i << "\n";
		}
	}	
	
	std::set<int>::iterator it=set.end();
	std::advance(it,-3);
	//set.erase(it,set.end());
	std::cout << *it << "\n";
	
	int arr[]={6,7,8,9};
	set.insert(arr,arr+4);
	
	if(!set.empty()){
		for(auto i:set){
			std::cout << i << "\n";
		}
	}
	
	auto val=set.find(6);
	std::cout << "Found: " << *val << "\n";
	
	auto eight=set.lower_bound(8);
	std::cout << "8: " << *eight << "\n";
	
	auto nine=set.upper_bound(9);
	std::cout << "9: " << *eight << "\n";
	
	std::set<int> set1={10,11};
	set.swap(set1);
	
	if(!set.empty()){
		for(auto i:set){
			std::cout << i << "\n";
		}
	}
	
	return 0;
	
}
