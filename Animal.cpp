#include <string>

class Animal{
	public:
		Animal();
		Animal(const Animal& orig);
		virtual ~Animal();
		std::string name;
	private:
};
