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
	
	std::multiset<int> mset={1,6,1,2,3,5,4,4,5};
	
	if(!mset.empty()){
		for(auto i:mset){
			std::cout << i << "\n";
		}
	}
	
	std::map<int,std::string> map1;
	map1.insert(std::pair<int,std::string> (1,"Hakan"));
	map1.insert(std::pair<int,std::string> (2,"Yigit"));
	map1.insert(std::pair<int,std::string> (3,"Melih"));
	
	auto match=map1.find(1);
	std::cout << match->second << "\n";
	
	std::map<int,std::string>::iterator it1;
	for(it1=map1.begin();it1!=map1.end();it1++){
		std::cout << "Key: " << it1->first << "\n";
		std::cout << "Name: " << it1->second << "\n";
	}
	return 0;
	
}
