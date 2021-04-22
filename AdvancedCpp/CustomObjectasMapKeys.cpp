#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person {
private:
    std::string name;
    int age;
public:
    Person(): name(""), age(0) {}

    Person(const Person& person) {
        this->name = person.name;
        this->age = person.age;
    }

    Person(std::string name,int age) : name(name), age(age){}

    void print() const {
        std::cout << this->name << ":" << this->age << std::endl;
    }

    // Operator overloading
    // Sequence the Person object with related to age / name
    bool operator < (const Person& person) const {
        return this->name < person.name;
    }
};

int main() {
    std::map<Person, int> person;
    person[Person("Hakan", 24)] = 1;
    person[Person("Yigit", 24)] = 3;
    person[Person("Melih", 24)] = 2;

    for (std::map<Person,int>::iterator it = person.begin(); it != person.end(); it++)
    {
        it->first.print();
    }
    return 0;
}