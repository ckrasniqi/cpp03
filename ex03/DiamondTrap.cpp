#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default"){
	std::cout << "DiamondTrap's default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name){
	_type = "DiamondTrap";
	_hitPoints = FragTrap->_hit
}
