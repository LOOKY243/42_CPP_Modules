#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource Default Constructor has been called" << std::endl;
    for (int i = 0; i < 4; i++)
        _sourceMats[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "MateriaSource Copy Constructor has been called" << std::endl;
    for (int i = 0; i < 4; i++)
	{
		if (other._sourceMats[i])
        	_sourceMats[i] = other._sourceMats[i]->clone();
		else
			_sourceMats[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource Copy assignement operator has been called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
            delete _sourceMats[i];
			if (other._sourceMats[i])
				_sourceMats[i] = other._sourceMats[i]->clone();
			else
				_sourceMats[i] = NULL;
		}
	}
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor has been called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete _sourceMats[i];
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << "Materia doesn't exist" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_sourceMats[i])
		{
			std::cout << "Materia has succesfully been learnt" << std::endl;
			_sourceMats[i] = materia;
			return ;
		}
	}
	std::cout << "Materia couldn't be learnt" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_sourceMats[i] && _sourceMats[i]->getType() == type)
		{
			std::cout << "Materia has succesfully been created" << std::endl;
			return _sourceMats[i]->clone();
		}
	}
	std::cout << "Materia couldn't be created" << std::endl;
	return 0;
}