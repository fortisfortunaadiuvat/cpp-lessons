#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <fstream>

std::vector<std::string> Stringtovector(std::string thestr,char seperator);

int main(){
	
	std::ofstream writetofile;
	std::ifstream readfromfile;
	std::string txttowrite="";
	std::string txtfromfile="";
	
	writetofile.open("test.txt",std::ios_base::out | std::ios_base::trunc);
	if(writetofile.is_open()){
		//writetofile << "Beginning of file\n";
		std::cout << "Enter data to write : ";
		getline(std::cin,txttowrite);
		writetofile << txttowrite;
		writetofile.close();
	}
	
	readfromfile.open("test.txt",std::ios_base::in);
	if(readfromfile.is_open()){
		while(readfromfile.good()){
			getline(readfromfile,txtfromfile);
			std::cout << txtfromfile << "\n";
			
			std::vector<std::string> vec=Stringtovector(txtfromfile,' ');
			int wordsinline=vec.size();
			std::cout << "Words in line: " << wordsinline << "\n";
			int charcount=0;
			for(auto word:vec){
				for(auto letter:word){
					charcount ++;
				}
			}
			int avgnumchars=charcount/wordsinline;
			std::cout << "Average word length: " << avgnumchars << "\n";
			
		}
		readfromfile.close();
	}
	
	return 0;
	
}

std::vector<std::string> Stringtovector(std::string thestr,char seperator){
	
	std::vector<std::string> vecwords;
	std::stringstream ss(thestr);
	std::string indvstr;
	
	while(getline(ss,indvstr,seperator)){
		vecwords.push_back(indvstr);
	}
	
}
