#include "Account.hpp"
#include <ctime>
#include <iostream>

int	_nbAccounts = 0;
int	_totalAmount = 0;
int	_totalNbDeposits = 0;
int	_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _accountIndex(_nbAccounts), _nbDeposits(0), _nbWithdrawals(0)
{
    _amount = 0;
    _amount = initial_deposit;
    _displayTimestamp();
    _totalAmount = initial_deposit;
    std::cout << "index:" << _accountIndex << ":amount:" << _amount << ";created" << std::endl;
    _nbAccounts++;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ":amount:" << _amount << ";closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbWithdrawals -= _nbWithdrawals;
    _totalNbDeposits -= _nbDeposits;
}

void Account::_displayTimestamp(void)
{
    std::time_t  currentTime;
    char    buffer[80];

    std::time(&currentTime);
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&currentTime));
    std::cout << "[" << buffer << "] ";
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << getNbAccounts();
    std::cout << getTotalAmount();
    std::cout << getNbDeposits();
    std::cout << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "Accounts:" << _nbAccounts << ";total:" << _totalAmount
        << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _totalAmount += deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit"
        << deposit << ";amount:" << _amount << ";nb_deposit:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (_amount - withdrawal >= 0)
    {
        _totalAmount -= withdrawal;
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal"
            << withdrawal << ";amount:" << _amount << ";nb_withdrawal:" << _nbWithdrawals << std::endl;
        return (true);
    }
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal"
            << ":refused" << std::endl;
    return (false);
}

int    Account::checkAmount(void) const
{
    return _amount;
}