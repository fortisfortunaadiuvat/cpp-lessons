#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>

int main(){
	
 // Listing 8.4
 // Allocating and deleting a pointer

	int localVariable = 5;
	int * pLocal= &localVariable;
	int * pHeap = new int;
	*pHeap = 7;

	std::cout <<  localVariable << "\n";
	std::cout << *pLocal << "\n";
	std::cout << *pHeap << "\n";
	std::cout << pHeap << "\n";
	
	delete pHeap;

	pHeap = new int;
	*pHeap = 9;
	std::cout << *pHeap << "\n";
	std::cout << pHeap << "\n";

	delete pHeap;

	return 0;
}
