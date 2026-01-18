#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	ClapTrap clap("RoboCop");
	ScavTrap scav("Guard");

	clap.attack("a handsome bully");
	scav.attack("a threat to the gate");
	clap.takeDamage(5);
	scav.takeDamage(4);
	clap.beRepaired(5);
	scav.beRepaired(4);
	clap.takeDamage(10);
	scav.takeDamage(10);
	clap.attack("the same bully");
	scav.guardGate();
	clap.takeDamage(2);
	return 0;
}
