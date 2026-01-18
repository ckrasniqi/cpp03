#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default"){
	_type = "Default";
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap's default constructor called!" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name){
	// _name = name; ClapTrap is doing this one and we don't need to do it twice
	_type = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap's default constructor called!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other){
	std::cout << "ScavTrap's copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other ){
	std::cout << "ScavTrap's copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::attack( const std::string &target ){
	if (_hitPoints == 0){
		std::cout << _name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0){
		std::cout << _name << " has insufficient amount of Energy points" << std::endl;
		std::cout << "Amount of Energy points: " << _energyPoints << std::endl;
		return;
	}
	std::cout << _name << " attacks "
			  << target << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate(){
	if (_hitPoints == 0){
		std::cout << _type << ": " << _name << " is dead and cannot guard the Gate!" << std::endl;
		return;
	}
	std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap's destructor called!" << std::endl;
}
