#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_name("Default"),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0) {
	std::cout << "Default constructor called!" << std::endl;
}


ClapTrap::ClapTrap(std::string name) :
_name(name),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0) {
	std::cout << "Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target){
	if (_hitPoints == 0){
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0){
		std::cout << "Claptrap " << _name << " has insufficient amount of Energy points" << std::endl;
		std::cout << "Amount of Energy points: " << _energyPoints << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks "
				  << target << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints == 0){
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (_hitPoints > amount){
		std::cout << "ClapTrap " << _name << " loses "
				  << amount << " hit points."
				  << std::endl;
		_hitPoints -= amount;
		std::cout << "Hit points left: " << _hitPoints << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " loses "
			  << amount << " hit points and dies in the process! :("
			  << std::endl;
	_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hitPoints == 0){
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0){
		std::cout << "Claptrap " << _name << " has insufficient amount of Energy points" << std::endl;
		std::cout << "Amount of Energy points: " << _energyPoints << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " regains "
			<< amount << " hit points."
			<< std::endl;
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "Hit points left: " << _hitPoints << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called!" << std::endl;
}
