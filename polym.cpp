#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <functional>
#include <iterator>
#include <memory>
#include <stdio.h>

class Pizza{
	public:
		virtual void MakePizza()=0;
};

class NYStyleCrust{
	public:
		std::string AddIngredient(){
			return "Crust so tin you can see through it\n";
		}
};

class DeepDishCrust{
	public:
		std::string AddIngredient(){
		 	return "Super Awesome Chikago Deep Dish\n";
		}
};

template <typename T>
class LotsofMeat: public T{
	public:
		std::string AddIngredient(){
			return "Lots of Random Meat, "+ T::AddIngredient();
		}
};

template <typename T>
class Vegan: public T{
	public:
		std::string AddIngredient(){
			return "Vegan Cheese,Veggies, "+ T::AddIngredient();
		}
};

template <typename T>
class MeatNYStyle: public T,public Pizza{
	public:
		void MakePizza(){
			std::cout << "Meat NY Style Pizza : " << T::AddIngredient() ;
		}
};

template <typename T>
class VeganDeepDish: public T,public Pizza{
	public:
		void MakePizza(){
			std::cout << "Vegan Deep Dish : " << T::AddIngredient() ;
		}
};


int main(){
	
	std::vector<std::unique_ptr<Pizza>> pizzaOrders;
	pizzaOrders.emplace_back(new MeatNYStyle<LotsofMeat<NYStyleCrust>>());
	pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());
	
	for(auto &pizza:pizzaOrders){
		pizza->MakePizza();
	}
	
	return 0;
	
}
