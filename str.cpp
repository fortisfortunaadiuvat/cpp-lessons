#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

std::vector<int> findsubstrmatch(std::string thestr,std::string substr);

std::string Replaceallsubstring(std::string thestr,std::string substr,std::string newstr);

int main(){
	
	std::cout << Replaceallsubstring("to know or not to know","know","be") << "\n";
	
	return 0;
	
}

std::vector<int> findsubstrmatch(std::string thestr,std::string substr){
	
	std::vector<int> matches;
	int index=thestr.find(substr,0);
	
	while(index != std::string::npos){
		matches.push_back(index);
		index=thestr.find(substr,index+1);
	}
	
	return matches;
	
}

std::string Replaceallsubstring(std::string thestr,std::string substr,std::string newstr){
	
	std::vector<int> matches=findsubstrmatch(thestr,substr);
	
	if(matches.size() != 0){
		int lengthdif=newstr.size() - substr.size();
		int timeloop=0;
		for(auto index: matches){
			thestr.replace(index+(timeloop*lengthdif),substr.size(),newstr.size());
			timeloop++;
		}
	}
	
	return thestr;
	
}

