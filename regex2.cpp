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
#include <regex>

void PrintMatches(std::string str,std::regex reg){
	std::smatch matches;
	std::cout << std::boolalpha;
	while(std::regex_search(str,matches,reg)){
		/*std::cout << "Is there a matches: " << matches.ready() << "\n";
		std::cout << "Are there no matches: " << matches.empty() << "\n";
		std::cout << "Number of matches: " << matches.size() << "\n";*/
		std::cout << matches.str(1) << "\n";
		str=matches.suffix().str();
		std::cout << "\n";
	}
}

void PrintMatches2(std::string str,std::regex reg){
	std::sregex_iterator currentmatches(str.begin(),str.end(),reg);
	std::sregex_iterator lastmatch;
	while(currentmatches!=lastmatch){
		std::smatch match=*currentmatches;
		std::cout << match.str() << "\n";
		currentmatches++;
	}
	std::cout << "\n";
}

int main(){
	
	std::string str="cat cats";
	std::regex reg("([cat]+s?)");
	PrintMatches(str,reg);
	
	std::string str1="doctor doctors doctor's";
	std::regex reg1("([doctor]+['s]*)");
	PrintMatches(str1,reg1);
	
	std::string str2="doctor doctors doctor's";
	std::regex reg2("([doctor]+['s]{0,2})");
	PrintMatches(str2,reg2);
	
	std::string str3="just some words\n and some some\n and more";
	std::regex reg3("[\r]?\n");
	std::string line=std::regex_replace(str3,reg3," ");
	std::cout << line << "\n\n";
	
	std::string str4="<name>Life on Mars</name><name>Freaks n Geeks</name>";
	std::regex reg4("<name>(.*?)</name>");
	PrintMatches(str4,reg4);
	
	//word boundaries
	std::string str5="ape was at the apex";
	std::regex reg5("(\\bape\\b)");
	PrintMatches(str5,reg5);
	
	//string boundaries
	std::string str6="Match everything up to@";
	std::regex reg6("(^.*[^@])");
	PrintMatches(str6,reg6);
	
	std::string str7="@ Get this string";
	std::regex reg7("([^@\\s].*$)");
	PrintMatches(str7,reg7);
	
	std::string str8="206-478-3001 207-568-4001 208-689-5001";
	std::regex reg8(".{3}-(.{8})");
	PrintMatches(str8,reg8);
	
	std::string str9="My number is 554-885-6733";
	std::regex reg9("(.{3})-(.*)-(.*)");
	std::smatch matches;
	if(std::regex_search(str9,matches,reg9)){
		for(int i=1;i<matches.size();i++){
			std::cout << matches[i] << "\n";
		}
	}
	
	return 0;
	
}
