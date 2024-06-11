#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();

    std::cout << "------------------------\n" << std::endl;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "------------------------\n" << std::endl;

    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    std::cout << "------------------------\n" << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    std::cout << "------------------------\n" << std::endl;

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);

    me->unequip(1);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    return 0;
}