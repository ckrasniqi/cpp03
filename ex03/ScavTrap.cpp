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
	std::cout << "ScavTrap's parameterized constructor called!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other){
	std::cout << "ScavTrap's copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other ){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap's copy assignment operator called" << std::endl;
	return *this;
}

void ScavTrap::attack( const std::string &target ){
	ClapTrap::attack(target);
}

void ScavTrap::guardGate(){
	if (_hitPoints == 0){
		std::cout << _type << ": " << _name << " is dead and cannot guard the Gate!" << std::endl;
		return;
	}
	std::cout << _type << ": " << _name << " is now in Gatekeeper mode." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap's destructor called!" << std::endl;
}
