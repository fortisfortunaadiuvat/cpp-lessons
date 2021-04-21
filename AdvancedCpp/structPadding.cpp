#include <iostream>
#include <fstream>

using namespace std;

typedef struct Person1{
    char c;
    double d;
    short int i;
} person1;

typedef struct Person2{
    double d;
    short int i;
    char c;

} person2;

int main()
{
    std::cout << "size of first person is: " << sizeof(person1) << std::endl;
    std::cout << "size of second person is: " << sizeof(person2) << std::endl;

    return 0;
}
