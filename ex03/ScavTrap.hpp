#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
// by adding the virtual we tell the compiler to create a single
// shared instance of ClapTrap

class ScavTrap : virtual public ClapTrap{
	public:
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &other );
		ScavTrap &operator=( const ScavTrap &other );
		~ScavTrap();

		void	attack( const std::string& target );
		void	guardGate();
};

#endif
