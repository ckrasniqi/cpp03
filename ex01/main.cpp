#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void printHeader( std::string title ){
	std::cout << "\n==========================================" << std::endl;
	std::cout << "         " << title << std::endl;
	std::cout << "==========================================" << std::endl;
}

int main(){

	printHeader("CONSTRUCTION CHAINING");
	{
		std::cout << "--- Creating a ScavTrap named 'Serena' ---" << std::endl;
		ScavTrap scav("Serena");
	}

	printHeader("BASIC FUNCTIONALITY & STATS");
	ScavTrap scav("Scav-V");
	ClapTrap clap("Clap-C");


	scav.attack("a training dummy");
	clap.attack("the same dummy");

	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();


	printHeader("ENERGY DEPLETION TEST");
	ClapTrap weakling("Weakling");
	std::cout << "Weakling tries to attack 11 times (Energy is 10)..." << std::endl;
	for (int i = 0; i < 11; i++) {
		weakling.attack("the air");
	}
	weakling.beRepaired(5);

	printHeader("DEATH & RESILIENCE TEST");
	ScavTrap target("TargetBot");
	target.takeDamage(99);
	target.beRepaired(1);
	target.takeDamage(100);
	target.attack("the attacker");
	target.beRepaired(10);
	target.guardGate();

	return 0;
}
