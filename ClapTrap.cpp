#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_name("Limi"),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0) {
	std::cout << "Default constructor called!" << std::endl;

}

void ClapTrap::attack(const std::string &target){
	if (_energyPoints >= 1){
		std::cout << "ClapTrap " << _name << " attacks "
				  << &target << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
	} else {
		std::cout << "Claptrap " << _name << " has insufficient amount of Energy points" << std::endl;
		std::cout << "Amount of Energy points: " << _energyPoints << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints > amount){
		std::cout << "ClapTrap " << _name << " loses "
				  << amount << " hit points."
				  << std::endl;
		std::cout << "Hit points left: " << _hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " loses "
				  << amount << " hit points and dies in the process! :("
				  << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints >= 1){
		std::cout << "ClapTrap " << _name << " regains "
				<< amount << " hit points."
				<< std::endl;
		std::cout << "Hit points: " << _hitPoints << std::endl;
	} else {
		std::cout << "Claptrap " << _name << " has insufficient amount of Energy points" << std::endl;
		std::cout << "Amount of Energy points: " << _energyPoints << std::endl;
	}
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called!" << std::endl;
}
