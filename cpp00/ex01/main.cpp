#include "PhoneBook.hpp"

int main(void)
{
    string input = "";
    PhoneBook   phonebook;

    while (true)
    {
        getline(std::cin, input);
        if (input == "ADD")
            phonebook.AddContact();
        else if (input == "SEARCH")
            phonebook.SelectContacts();
        else if (input == "EXIT")
            break;
        else
            cout << RED "Wrong input" WHI << endl;
    }
}