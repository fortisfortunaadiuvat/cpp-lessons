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
	
	//back reference
	std::string str="The cat cat fell out the window";
	std::regex reg("(\\b\\w+)\\s+\\1");
	PrintMatches(str,reg);
	
	std::string str1="<a href='#'><b>The link </b> </a>";
	std::regex reg1("<b>(.*?)</b>");
	
	std::string result;
	std::regex_replace(std::back_inserter(result),
					str1.begin(),str1.end(),reg1,"$1");
	
	std::cout << result << "\n\n";
	
	std::string str2="554-885-6733";
	std::regex reg2("([\\d]{3})-([\\d]{3})-([\\d]{4})");
	
	std::string result1;
	std::regex_replace(std::back_inserter(result1),
					str2.begin(),str2.end(),reg2,"($1)$2$3");
	
	std::cout << result1 << "\n\n";
	
	/*<a href='https://www.youtube.com'>www.youtube.com</a>
	<a href='https://www.google.com'>www.google.com</a>*/
	
	std::string str3="https://www.youtube.com\n"
					"http://www.google.com";
	std::regex reg3("(https?//([\\w]+))");
	
	std::string result3;
	std::regex_replace(std::back_inserter(result3),
					str3.begin(),str3.end(),reg3,"<a href='$1'>$2</a>\n");
	
	std::cout << result3 << "\n\n";
	
	//look ahead:match but not return
	std::string str4=" one two three four ";
	std::regex reg4("(\\w+(?=\\b))");
	PrintMatches(str4,reg4);
	
	//conditional or 
	std::string str5="1. Dog 2. Cat 3. Turtle";
	std::regex reg5("\\d\\.\\s(Dog|Cat)");
	PrintMatches(str5,reg5);
	
	std::string str6="12345 12345-1234 1234 12346-333";
	std::regex reg6("(\\d{5}-\\d{4}|\\d{5}\\s)");
	PrintMatches(str6,reg6);
	
	return 0;
	
}
