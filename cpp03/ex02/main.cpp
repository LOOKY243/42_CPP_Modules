#include "FragTrap.hpp"

using std::cout;
using std::endl;

int main(){
	ClapTrap clap("Luffy");
	ScavTrap scav("Zorro");
	FragTrap frag("Sanji");

	cout << endl << endl;
	clap.attack("Zorro");
	clap.takeDamage(5);
	clap.beRepaired(10);
	scav.guardGate();
	scav.attack("Sanji");
	scav.beRepaired(10);
	scav.takeDamage(10);
	scav.guardGate();
	scav.attack("Luffy");
	frag.highFivesGuys();
	frag.attack("Zorro");
	frag.beRepaired(10);
	frag.takeDamage(10);
	cout << endl << endl;
}