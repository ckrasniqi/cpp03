#include "ClapTrap.hpp"

int main(){
	ClapTrap clap("Limi");

	clap.attack("a handsome bully");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(10); // it should trigger the death message
	clap.attack("the same bully");
	clap.takeDamage(2);
	return 0;
}
