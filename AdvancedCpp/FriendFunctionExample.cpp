#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
private:
    int id;
    std::string name;
public:
    Test() : id(0),name(""){}

    Test(int id,std::string name): id(id),name(name){}

    void print() {
        std::cout << "id: " << this->id << " name: " << this->name << std::endl;
    }

    // Friend function to access private member value.
    friend bool compare(const Test& test1, const Test& test2);
};

bool compare(const Test& test1,const Test& test2) {
    return test1.name < test2.name;
}

int main() {
    std::vector<Test> test;
    
    test.push_back(Test(5,"Hakan"));
    test.push_back(Test(10, "Melih"));
    test.push_back(Test(7, "Yusuf"));
    test.push_back(Test(3, "Bora"));
    test.push_back(Test(6, "Yigit"));

    // We can change the param. Like:
    // std::sort(test.begin(),test.begin()+2,compare);
    std::sort(test.begin(), test.end(), compare);

    for (int i = 0; i < test.size(); i++)
    {
        test[i].print();
    }

    return 0;
}