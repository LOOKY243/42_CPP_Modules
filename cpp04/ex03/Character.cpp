#include "Character.hpp"

Character::Character()
{
    std::cout << "Character Default Constructor has been called" << std::endl;
    _name = "None";
    remove = NULL;
    for (int i = 0; i < 4; i++)
        _mats[i] = 0;
}

Character::Character(std::string name)
{
    std::cout << "Character Parameterized Constructor has been called" << std::endl;
    _name = name;
    remove = NULL;
    for (int i = 0; i < 4; i++)
        _mats[i] = 0;
}

Character::Character(const Character &other)
{
    std::cout << "Character Copy Constructor has been called" << std::endl;
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Character Copy assignment operator has been called" << std::endl;
    _name = other._name;
    remove = other.remove;
    for (int i = 0; i < 4; i++)
    {
        if (other._mats[i])
			_mats[i] = other._mats[i]->clone();
		else
			_mats[i] = NULL;
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character Destructor has been called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_mats[i])
            delete _mats[i];
    }
	List *cur, *tmp;

	cur = remove;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		delete tmp->value;
		delete tmp;
	}
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_mats[i])
        {
            _mats[i] = m;
            std::cout << m->getType() << " has succesfully been equiped!" << std::endl;
            return ;
        }
    }
    std::cout << "Inventory is already full" << std::endl;
}

void Character::unequip(int index)
{
    if (index > 3 || index < 0)
    {
        std::cout << "Index value must be between 0 and 3" << std::endl;
        return ;
    }
    if (_mats[index] == 0)
    {
        std::cout << "The slot is already empty" << std::endl;
        return ;
    }
	if (!remove)
		remove = new List(_mats[index]);
	else
	{
		List *last;

		last = remove;
		while (last->next)
			last = last->next;
		last->next = new List(_mats[index]);
	}
_mats[index] = 0;
    std::cout << "Slot " << index << " has been unequiped succesfully!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx > 3 || idx < 0)
    {
        std::cout << "Index value must be between 0 and 3" << std::endl;
        return ;
    }
    if (_mats[idx])
        _mats[idx]->use(target);
    else
        std::cout << "Slot is empty" << std::endl;
}