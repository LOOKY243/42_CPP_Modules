#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define BLA "\x1B[30m"
# define RED "\x1B[31m"
# define GRE "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYA "\x1B[36m"
# define WHI "\x1B[37m"

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class PhoneBook {

    private:
        Contact contacts[8];
        int     index;
        int     nb_contact;

    public:
        PhoneBook();
        ~PhoneBook();
        void SelectContacts();
        void    AddContact();
};

#endif