#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default"){
	_type = "Default";
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap's default constructor called!" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name){
	_type = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap's default constructor called!" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other){
	std::cout << "FragTrap's copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &other ){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap's copy assignment operator called" << std::endl;
	return *this;
}

void FragTrap::attack( const std::string &target ){
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

void FragTrap::highFivesGuys( void ){
	if (_hitPoints == 0) {
		std::cout << _type << ": " << _name << " is too dead to high-five anyone." << std::endl;
		return;
	}
	std::cout << _type << ": " << _name << " says: High five, everyone! Up top! ✋" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap's destructor called!" << std::endl;
}
