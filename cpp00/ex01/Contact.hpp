#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <cstdlib>
#include <iostream>

using std::string;

class Contact {

    private:
        string firstName;
        string lastName;
        string nickName;
        string phoneNumber;
        string darkSecret;
    
    private:

    public:
        Contact();
        ~Contact();
        void    SetContact(string first, string last, string nick, string num, string secret);
        string  GetInfo(int index);
};

#endif