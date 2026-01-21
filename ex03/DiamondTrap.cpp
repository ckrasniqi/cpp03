#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(""){
	_type = "Default";
	_name = "";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap's default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name){
	_type = "DiamondTrap";
	_name = ClapTrap::_name + "_clap_name";
	_hitPoints = _hitPoints;
	_energyPoints = _energyPoints;
	_attackDamage = _attackDamage;
	std::cout << "DiamondTrap's default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap(other){
	std::cout << "DiamondTrap's copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other ){
	std::cout << "DiamondTrap's copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

void DiamondTrap::attack( const std::string &target ){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	if (_hitPoints == 0){
		std::cout << _type << ": " << _name << " is dead and cannot speak!" << std::endl;
		return;
	}
	std::cout << _name << " this is from the private attribute of DiamondTrap's class" << std::endl;
	std::cout << ClapTrap::_name << " this is from the protected attribute of ClapTrap's class" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap's destructor called!" << std::endl;
}
