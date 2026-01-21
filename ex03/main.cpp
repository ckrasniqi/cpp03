#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void printHeader( std::string title ){
	std::cout << "\n==========================================" << std::endl;
	std::cout << "         " << title << std::endl;
	std::cout << "==========================================" << std::endl;
}

int main(){

	printHeader("CONSTRUCTION CHAINING");
	{
		std::cout << "--- Creating a DiamondTrap named 'Diamond' ---" << std::endl;
		DiamondTrap dia("Diamond");
	}

	printHeader("BASIC FUNCTIONALITY & STATS");
	ScavTrap scav("Scav-V");
	ClapTrap clap("Clap-C");
	DiamondTrap dia("Diamond2");

	scav.attack("a training dummy");
	clap.attack("the same dummy");
	dia.attack("the wall"); //attacks with 30 points

	printHeader("SCAVTRAP TESTS");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();
	scav.takeDamage(100);
	scav.guardGate();

	printHeader("DIAMONDTRAP TESTS");
	dia.takeDamage(99);
	dia.beRepaired(9);
	dia.whoAmI();
	dia.takeDamage(10);
	dia.whoAmI();

	printHeader("FRAGTRAP TESTS");
	FragTrap frag("Fraggy");
	frag.attack("a concrete wall");
	frag.highFivesGuys();
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.takeDamage(100);
	frag.highFivesGuys();

	printHeader("ENERGY DEPLETION TEST");
	// DiamondTrap (50 energy Points), ScavTrap(50), FragTrap(100)
	ClapTrap weakling("Weakling");
	std::cout << "Weakling tries to attack 11 times (Energy is 10)..." << std::endl;
	for (int i = 0; i < 11; i++) {
		weakling.attack("the air");
	}
	weakling.beRepaired(5);

	printHeader("ORTHODOX CANONICAL FORM TEST");
	DiamondTrap original("Original");
	original.takeDamage(50);

	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	DiamondTrap copy(original);
	std::cout << "Copy attacks to verify it inherited attributes correctly:" << std::endl;
	copy.attack("a clone");

	std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
	DiamondTrap assigned("Newbie");
	assigned = original;
	assigned.whoAmI();

	printHeader("END OF TESTS - DESTRUCTORS INCOMING");

	return 0;
}
