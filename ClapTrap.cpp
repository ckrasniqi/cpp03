#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_name("Limi"),
_hitPoints(10),
_energyPoints(10),
_attackDamage(10) {
	std::cout << "Default constructor called!" << std::endl;

}

void ClapTrap::attack(const std::string &target){

	std::cout << "ClapTrap " << _name << " attacks "
			  << &target << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount){

	std::cout << "ClapTrap " << _name << " loses "
			  << amount << " hit points."
			  << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount){

	std::cout << "ClapTrap " << _name << " regains "
			  << amount << " hit points."
			  << std::endl;

}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called!" << std::endl;

}
