#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat boss;
	AForm	*rrf;
	std::string input = "presidential pardon";

	boss = Bureaucrat("Boss", 1);

	std::cout << std::endl;
	rrf = intern.makeForm(input, "Bender");

	if (rrf)
	{
		rrf->beSigned(boss);
		rrf->execute(boss);
		delete rrf;
	}

	std::cout << std::endl;
}