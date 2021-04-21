#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push , 1)
struct Person {
    char name[20];
    int age;
    float weight;
};

int main()
{
    Person someone = {"Khan",23,.8f};
    string fileName = "test.bin";

    // Write binary file
    ofstream outputFile;

    outputFile.open(fileName , ios::binary);
    if(outputFile.is_open()){
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        outputFile.close();
    }
    else{
        std::cout << "File could not opened!";
    }

    Person someoneElse = {};
    // Read binary file
    ifstream inputFile;

    inputFile.open(fileName , ios::binary);
    if(inputFile.is_open()){
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        inputFile.close();
    }
    else{
        std::cout << "File could not opened!";
    }

    std::cout << someoneElse.name << "," << someoneElse.age << "," << someoneElse.weight << std::endl;


    return 0;
}
