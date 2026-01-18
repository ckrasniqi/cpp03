#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	printHeader("FRAGTRAP TESTS");
	FragTrap frag("Fraggy");
	frag.attack("a concrete wall");
	frag.highFivesGuys();
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.takeDamage(100);
	frag.highFivesGuys();

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

	printHeader("ORTHODOX CANONICAL FORM TEST");
	ScavTrap original("Original");
	original.takeDamage(50);

	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	ScavTrap copy(original);
	std::cout << "Copy attacks to verify it inherited attributes correctly:" << std::endl;
	copy.attack("a clone");

	std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
	ScavTrap assigned("Newbie");
	assigned = original;
	assigned.guardGate();

	printHeader("END OF TESTS - DESTRUCTORS INCOMING");

	return 0;
}
