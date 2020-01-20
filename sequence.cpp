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
#include <deque>
#include <list>
#include <forward_list>

bool iseven(const int &val){
	return (val%2)==0;
}

int main(){
	
	std::deque<int> deq1;
	deq1.assign({11,12});
	deq1.push_back(5);
	deq1.push_front(1);
	
	std::deque<int>::iterator it=deq1.begin()+1;
	deq1.insert(it,3);
	int temparr[5]={6,7,8,9,10};
	deq1.insert(deq1.end(),temparr,temparr+5);
	std::cout << "Size: " << deq1.size() << "\n\n";
	//deq1.erase(deq1.begin(),deq1.begin()+2);
	deq1.pop_front();
	deq1.pop_back();
	
	for(int i:deq1){
		std::cout << i << "\n";
	}
	
	return 0;
	
}
