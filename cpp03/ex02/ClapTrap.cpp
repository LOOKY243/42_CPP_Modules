#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default contructor has been called" << std::endl;
    _name = "None";
    _hPoints = 10;
    _ePoints = 10;
    _ad = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap parameterized contructor has been called" << std::endl;
    _name = name;
    _hPoints = 10;
    _ePoints = 10;
    _ad = 5;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
        _name = other._name;
    _hPoints = other._hPoints;
    _ePoints = other._ePoints;
    _ad = other._ad;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    this->_name = other._name;
    this->_hPoints = other._hPoints;
    this->_ePoints = other._ePoints;
    this->_ad = other._ad;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (_ePoints > 0 && _hPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks "
            << target << ", causing " << _ad << " points of damage!" << std::endl;
        _ePoints--;
    }
    else if (_hPoints <= 0)
        std::cout << "Sadly " << _name << "has already died..." << std::endl;
    else
        std::cout << "Whoops... " << _name << " doesn't have enought points" << std::endl; 
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hPoints == 0)
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
    else if ((unsigned int)_hPoints < amount)
        _hPoints = 0;
    else
        _hPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_ePoints > 0 && _hPoints >= 0)
    {
        _hPoints += amount;
        std::cout << "ClapTrap " << _name << " regained "
            << amount << " points of health" << std::endl;
        _ePoints--;
    }
    else if (_hPoints <= 0)
        std::cout << "Sadly " << _name << "has already died..." << std::endl;
    else
        std::cout << "Whoops... " << _name << " doesn't have enought points" << std::endl; 
}

std::string ClapTrap::getName(void)
{
    return _name;
}
unsigned int ClapTrap::getEpoints(void)
{
    return _ePoints;
}
unsigned int ClapTrap::getHpoints(void)
{
    return _hPoints;
}

unsigned int ClapTrap::getAd(void)
{
    return _ad;
}