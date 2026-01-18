#ifndef FRAGTRAPP_HPP
#define FRAGTRAPP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap( std::string name );
		FragTrap( const FragTrap &other );
		FragTrap &operator=( const FragTrap &other );
		~FragTrap();

		void	attack( const std::string& target );
		void	highFivesGuys( void );
};

#endif
