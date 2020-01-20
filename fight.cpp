#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Warrior{
	public:
		std::string name;
		int health;
		int attack;
		int block;
		std::string GetName(){
			return name;
		}	
		void Setname(std::string name){
			this->name=name;
		}
		int GetHealth(){
			return health;
		}
		void Sethealth(int health){
			this->health=health;
		}
		int GetAttack(){
			return attack;
		}
		void SetAttack(int attack){
			this->attack=attack;
		}
		int GetBlock(){
			return block;
		}
		void SetBlock(int block){
			this->block=block;
		}
		int Attack(){
			return std::rand()% this->attack;
		}
		int Block(){
			return std::rand()% this->block;
		}
		
		void SetAll(std::string,int,int,int);
		Warrior(std::string,int,int,int);
		Warrior();
};

class Battle{
	public:
		static void StartFight(Warrior& warrior1,Warrior& warrior2){
			while(true){
				if(Battle::GetAttackResult(warrior1,warrior2).compare("Game Over")==0){
					std::cout << "Game Over\n";
					break;
				}
				if(Battle::GetAttackResult(warrior2,warrior1).compare("Game Over")==0){
					std::cout << "Game Over\n";
					break;
				}
			}
		}
		
		static std::string GetAttackResult(Warrior& warriorA,Warrior& warriorB){
			int warriorAAttackAttmp=warriorA.Attack();
			int warriorBBlockAttmp=warriorB.Block();
			int damage2warriorB=ceil(warriorAAttackAttmp-warriorBBlockAttmp);
			damage2warriorB=(damage2warriorB <= 0) ? 0:damage2warriorB;
			warriorB.health=warriorB.health-damage2warriorB;
			
			printf("%s attack %s and deals %d damage\n",
					warriorA.name.c_str(),
					warriorB.name.c_str(),
					damage2warriorB);
			printf("%s is down to %d health\n",
					warriorB.name.c_str(),
					warriorB.health);
				if(warriorB.health <= 0){
					printf("%s has died and %s is victorious\n",
							warriorB.name.c_str(),
							warriorA.name.c_str());
					return "Game Over";
				}
				else{
					return "Fight Again";
				}
		}
};

void Warrior::SetAll(std::string name,int health,int attack
					,int block){
		this->name=name;
		this->health=health;
		this->attack=attack;
		this->block=block;				
	}

Warrior::Warrior(std::string name,int health,int attack
					,int block){
		this->name=name;
		this->health=health;
		this->attack=attack;
		this->block=block;				
	}

int main(){
	
	srand(time(NULL));
	
	Warrior Thor("Thor",100,30,15);
	Warrior Hulk("Hulk",125,25,10);
	
	Battle::StartFight(Thor,Hulk);
	
	return 0;
	
}
