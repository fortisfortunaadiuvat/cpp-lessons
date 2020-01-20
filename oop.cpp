#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Animal{
	protected:
		std::string name;
		double height;
		double weight;
	
	public:
		std::string GetName(){
			return name;
		}	
		void Setname(std::string name){
			this->name=name;
		}
		double GetHeight(){
			return height;
		}
		void Setheight(double height){
			this->height=height;
		}
		double GetWeight(){
			return weight;
		}
		void SetWeight(double weight){
			this->weight=weight;
		}
		
		void SetAll(std::string,double,double);
		Animal(std::string,double,double);
		Animal();
		~Animal();
		
		static int numofanimals;
		
		static int GetnumofAnimals(){
			return numofanimals;
		}
		
		void tostring();
		
};

int Animal::numofanimals=0;

void Animal::SetAll(std::string name,double height,double weight){
	this->name=name;
	this->height=height;
	this->weight=weight;
  	Animal::numofanimals++;
}

Animal::Animal(std::string name,double height,double weight){
	this->name=name;
	this->height=height;
	this->weight=weight;
  	Animal::numofanimals++;
}

Animal::Animal(){
	this->name="";
	this->height=0;
	this->weight=0;
  	Animal::numofanimals++;
}

Animal::~Animal(){
	std::cout << "Animal " << this->name << " destroyed\n";
}

void Animal::tostring(){
	std::cout << this->name << " is " << this->height << " cms tall "
		<< this->weight << " kgs in weight\n";
}

class Dog: public Animal{
	private:
		std::string sound="woof";
	public:
		void makesound(){
			std::cout << "the dog " << this->GetName() << " says "
			 	<< this->sound << "\n";
	}
	
	Dog(std::string,double,double,std::string);
	Dog():Animal(){};
	void tostring();
};

Dog::Dog(std::string name,double height,double weight,std::string sound):
	Animal(name,height,weight){
		this->sound=sound;
	}
	
void Dog::tostring(){
	std::cout << this->name << " is " << this->GetHeight() << 
	" cms tall " << this->GetWeight() << " kgs in weight n says "
	<< this->sound << "\n";
}

int main(){
	
	Animal fred;
	//fred.tostring();
	fred.SetAll("Fred",70,10);
	fred.tostring();
	Dog spot("Spot",80,10,"Wooff");
	spot.tostring();
	
	std::cout << "number of animals s: " 
	<< Animal::GetnumofAnimals() << "\n";
	
	return 0;
	
}
