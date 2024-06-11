#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap _robot = DiamondTrap("Robot");
	_robot.whoAmI();
	_robot.guardGate();
	_robot.highFivesGuys();

	for (int i = 0; i < 10; i++)
	{
		_robot.attack("Human");
		_robot.takeDamage(3);
		_robot.beRepaired(2);
		std::cout << "Epoints = " << _robot.getEpoints() << std::endl;;
		std::cout << std::endl;
	}
}