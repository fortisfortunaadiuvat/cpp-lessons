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
		std::cout << "Is there a matches: " << matches.ready() << "\n";
		std::cout << "Are there no matches: " << matches.empty() << "\n";
		std::cout << "Number of matches: " << matches.size() << "\n";
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

	std::string str="The ape was at the apex";
	std::regex reg("(ape[^ ]?)");
	PrintMatches(str,reg);
	
	std::string str2="I picked the pickle";
	std::regex reg2("(pick([^ ]+)?)");
	PrintMatches2(str2,reg2);
	
	std::string str3="cat mat fat sat";
	std::regex reg3("([cmfs]at)");
	PrintMatches2(str3,reg3);
	
	std::string str4="rar car var";
	std::regex reg4("([rcv]ar)");
	PrintMatches2(str4,reg4);
	
	std::string str5="cat fat mat";
	std::regex reg5("([cfm]at)");
	std::string owl=std::regex_replace(str5,reg5,"owl");
	
	std::cout << owl << "\n\n";
	
	std::string str6="F.B.I I.S.R CIA";
	std::regex reg6("([^ ]\..\..\.)");
	PrintMatches2(str6,reg6);
	
	std::string str7="This is a\n multiline string\n that has many lines";
	std::regex reg7("\n");
	std::string nolinestr=std::regex_replace(str7,reg7," ");
	
	std::cout << nolinestr << "\n\n";
	
	std::string str8="12345";
	std::regex reg8("\\d");
	PrintMatches2(str8,reg8);
	
	std::string str9="123 1234 12345 123456 1234567";
	std::regex reg9("\\d{5,7}");
	PrintMatches2(str9,reg9);
	
	std::string str10="554-885-6733";
	std::regex reg10("\\w{3}-\\w{3}-\\w{4}");
	PrintMatches2(str10,reg10);
	
	std::string str11="Hakan Keles";
	std::regex reg11("\\w{2,20}\\s\\w{2,20}");
	PrintMatches2(str11,reg11);
	
	std::string str12="a as ape bug";
	std::regex reg12("a[a-z]+");
	PrintMatches2(str12,reg12);
	
	std::string str13="hakankeles4152@gmail.com";
	std::regex reg13("[\\w._%+-]{1,20}@[\\w.-]{2,20}.[A-Za-z]{2,3}");
	PrintMatches2(str13,reg13);
	
	return 0;
	
}
