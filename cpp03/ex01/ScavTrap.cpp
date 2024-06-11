#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("ScavTrap")
{
    std::cout << "ScavTrap Default constructor has been called" << std::endl;
    _hPoints = 100;
    _ePoints = 50;
    _ad = 20;
    _guardGate = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap parameterized constructor has been called" << std::endl;
    _hPoints = 100;
    _ePoints = 50;
    _ad = 20;
    _guardGate = false;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->_name = other._name;
    this->_hPoints = other._hPoints;
    this->_ePoints = other._ePoints;
    this->_ad = other._ad;
    this->_guardGate = other._guardGate;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    this->_name = other._name;
    this->_hPoints = other._hPoints;
    this->_ePoints = other._ePoints;
    this->_ad = other._ad;
    this->_guardGate = other._guardGate;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(std::string target)
{
    if (_ePoints > 0 || _hPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks "
                << target << ", causing " << _ad << " points of damage!" << std::endl;
        _ePoints--;
    }
    else if (_hPoints <= 0)
        std::cout << "Sadly " << _name << "has already died..." << std::endl;
    else
        std::cout << "Whoops... " << _name << " doesn't have enought points" << std::endl; 
}

void ScavTrap::guardGate()
{
    if (_hPoints > 0 && _guardGate == false)
    {
        std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
        _guardGate = true;
    }
    else if (_guardGate == true)
        _guardGate = false;
    else
    {
        std::cout << "ScavTrap can't activate Gate keeper mode beacause he's dead..." << std::endl;
    }
}

