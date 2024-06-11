#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("DiamondTrap")
{
    std::cout << "DiamondTrap Default constructor has been called" << std::endl;
    ClapTrap::_name = "Default_clap_name";
    _name = "DiamondTrap";
    _hPoints = FragTrap::_hPoints;
    _ePoints = ScavTrap::_ePoints;
    _ad = FragTrap::_ad;

}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap parameterized constructor has been called" << std::endl;
    _name = name;
    _hPoints = 10;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    ClapTrap::_name = other._name + "_clap_name";
    this->_name = other._name;
    this->_hPoints = other._hPoints;
    this->_ePoints = other._ePoints;
    this->_ad = other._ad;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    ClapTrap::_name = other._name + "_clap_name";
    this->_name = other._name;
    this->_hPoints = other._hPoints;
    this->_ePoints = other._ePoints;
    this->_ad = other._ad;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "my name is " << _name << " and my ClapTrap name is "
        << ClapTrap::_name << std::endl;
}