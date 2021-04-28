#include <iostream>

using namespace std;

class Test {
private:
    int id;
    std::string name;
public:
    Test() : id(0),name(""){}

    Test(int id,std::string name): id(id),name(name){}

    Test(const Test& other) {
        std::cout << "Copy constructor initialization!" << std::endl;
        this->id = other.id;
        this->name = other.name;
    }
    
    const Test& operator=(const Test& other) {
        std::cout << "operator overloading here!" << std::endl;
        this->id = other.id;
        this->name = other.name;

        return *this;
    }
    void print() {
        std::cout << "id: " << this->id << " name: " << this->name << std::endl;
    }

    friend ostream& operator<<(ostream &out, const Test& test) {
        out << test.id << ":" << test.name;
        return out;
    }

};

int main() {
    Test test1(20, "Mike");

    // Left shift operator overloading!
    std::cout << test1 << std::endl;

    Test test2;
    test2.operator=(test1);

    test2.print();

    return 0;
}