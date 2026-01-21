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

	printHeader("1. CONSTRUCTION & DESTRUCTION ORDER");
	{
		std::cout << "--- Creating DiamondTrap 'D-03' ---" << std::endl;
		std::cout << "Required: Clap -> Scav -> Frag -> Diamond" << std::endl;
		DiamondTrap diamond("D-03");
		std::cout << "\n--- Destruction starts here ---" << std::endl;
		std::cout << "Required: Diamond -> Frag -> Scav -> Clap" << std::endl;
	}

	printHeader("2. IDENTITY & WHOAMI TEST");
	{
		DiamondTrap diamond("Loki");
		std::cout << "Required: Name should be 'Loki', Clap name 'Loki_clap_name'" << std::endl;
		diamond.whoAmI();
	}

	printHeader("3. STATS & ATTACK DELEGATION");
	{
		DiamondTrap diamond("Monster");

		std::cout << "\n--- Testing ScavTrap::attack() delegation ---" << std::endl;
		std::cout << "Look at the message below. It should look like ScavTrap's attack." << std::endl;
		diamond.attack("a training dummy");

		std::cout << "\n--- Testing Energy Points (from ScavTrap: 50) ---" << std::endl;
		std::cout << "Starting energy should be 50. Attacking 50 times..." << std::endl;
		for (int i = 0; i < 50; ++i) {
			diamond.attack("target");
		}
		std::cout << "The 51st attack should fail due to energy depletion:" << std::endl;
		diamond.attack("one last target");

		std::cout << "\n--- Testing Hit Points (from FragTrap: 100) ---" << std::endl;
		diamond.beRepaired(10); // Should fail due to energy, but if it had energy:
		// Let's check death at 100.
		diamond.takeDamage(99);
		std::cout << "Should have 1 HP left." << std::endl;
		diamond.takeDamage(1);
		std::cout << "Should be dead now." << std::endl;
		diamond.whoAmI(); // Should show death message if implemented
	}

	printHeader("4. SPECIAL ABILITIES INHERITANCE");
	{
		DiamondTrap diamond("Hybrid");
		std::cout << "Can it guard the gate (Scav)? ";
		diamond.guardGate();
		std::cout << "Can it high five (Frag)? ";
		diamond.highFivesGuys();
	}

	printHeader("5. ORTHODOX CANONICAL FORM");
	{
		DiamondTrap original("Alpha");
		DiamondTrap copy(original);
		DiamondTrap assigned("Beta");
		assigned = original;

		std::cout << "Original identity:" << std::endl;
		original.whoAmI();
		std::cout << "Copy identity:" << std::endl;
		copy.whoAmI();
		std::cout << "Assigned identity:" << std::endl;
		assigned.whoAmI();
	}
	return 0;
}
