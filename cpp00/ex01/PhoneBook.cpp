#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
    index = 0;
    nb_contact = 0;
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::SelectContacts(void)
{
    string  user;
    int     iuser;

    if (nb_contact == 0)
    {
        cout << RED "No user has been added." WHI << endl;
        return ;
    }
    cout << CYA "┌-------------------------------------------┐" WHI << endl;
    cout << CYA "|     Index| FirstName| LastName | NickName |" WHI << endl;
    cout << CYA "└-------------------------------------------┘" WHI << endl;
    for (int i = 0; i < nb_contact; i++)
    {
        string first = contacts[i].GetInfo(1);
        string last = contacts[i].GetInfo(2);
        string nick = contacts[i].GetInfo(3);

        cout << CYA "|" << std::setw(10) << i + 1;
        if (first.length() > 9)
            cout << "|" << first.substr(0, 9) << ".";
        else
            cout << "|" << std::setw(10) << first;
        if (last.length() > 9)
            cout << "|" << last.substr(0, 9) << ".";
        else
            cout << "|" << std::setw(10) << last;
        if (nick.length() > 9)
            cout << "|" << nick.substr(0, 9) << ".|" << endl;
        else
            cout << "|" << std::setw(10) << nick << "|" << endl;
        cout << "└-------------------------------------------┘" WHI << endl;
    }
    getline(cin, user);
    iuser = atoi(user.c_str()) - 1;
    if (iuser + 1 > nb_contact || iuser == -1)
        cout << RED "User " << user << " doesn't exist." WHI << endl;
    else
    {
        cout << MAG << contacts[iuser].GetInfo(1) << endl;
        cout << contacts[iuser].GetInfo(2) << endl;
        cout << contacts[iuser].GetInfo(3) << endl;
        cout << contacts[iuser].GetInfo(4) << endl;
        cout << contacts[iuser].GetInfo(5) << WHI << endl;
    }
}

void    PhoneBook::AddContact(void)
{
    string first, last, nick, num, secret;

    cout << GRE "First Name: " WHI;
    getline(cin, first);
    cout << GRE "Last Name: " WHI;
    getline(cin, last);
    cout << GRE "NickName: " WHI;
    getline(cin, nick);
    cout << GRE "Phone Number: " WHI;
    getline(cin, num);
    cout << GRE "Darkest Secret: " WHI;
    getline(cin, secret);

    if (first.empty() || last.empty() || nick.empty() || num.empty() || secret.empty())
        cout << RED "No Argument can be blank" WHI << endl;
    else
    {
        if (nb_contact < 8)
            nb_contact++;
        if (index == 8)
            index = 0;
        contacts[index].SetContact(first, last, nick, num, secret);
        index++;
    }
}