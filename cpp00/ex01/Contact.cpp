#include "Contact.hpp"

Contact::~Contact()
{
}

Contact::Contact()
{
    firstName = "first name";
    lastName = "last name";
    nickName = "nick name";
    phoneNumber = "phone number";
    darkSecret = "darkest secret";
}

void    Contact::SetContact(string first, string last, string nick, string num, string secret)
{
    firstName = first;
    lastName = last;
    nickName = nick;
    phoneNumber = num;
    darkSecret = secret;
}

string    Contact::GetInfo(int index)
{
    if (index == 1)
        return firstName;
    if (index == 2)
        return lastName;
    if (index == 3)
        return nickName;
    if (index == 4)
        return phoneNumber;
    else
        return darkSecret;
}