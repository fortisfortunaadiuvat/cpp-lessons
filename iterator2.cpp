#include <string>

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
	public:
		Animal();
		Animal(const Animal& orig);
		virtual ~Animal();
		std::string name;
	private:
};

#endif //ANIMAL_H
