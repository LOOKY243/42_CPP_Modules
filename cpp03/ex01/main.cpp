#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap _robot = ScavTrap("Robot");

	for (int i = 0; i < 10; i++)
	{
		_robot.attack("Human");
		_robot.guardGate();
		_robot.takeDamage(3);
		_robot.beRepaired(2);
		std::cout << std::endl;
	}
}