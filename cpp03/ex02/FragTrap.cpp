#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("FragTrap")
{
    std::cout << "FragTrap Default constructor has been called" << std::endl;
    _hPoints = 100;
    _ePoints = 100;
    _ad = 30;
}
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap parameterized constructor has been called" << std::endl;
    _hPoints = 100;
    _ePoints = 100;
    _ad = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    this->_name = other._name;
    this->_hPoints = other._hPoints;
    this->_ePoints = other._ePoints;
    this->_ad = other._ad;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    this->_name = other._name;
    this->_hPoints = other._hPoints;
    this->_ePoints = other._ePoints;
    this->_ad = other._ad;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    if (_hPoints > 0)
        std::cout << "FragTrap " << _name << "is requesting a high five!" << std::endl;
    else
        std::cout << "FragTrap" << _name << "can't request a high five beacause he's dead..." << std::endl;
}