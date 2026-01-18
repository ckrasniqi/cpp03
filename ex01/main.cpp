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
	return 0;
}
