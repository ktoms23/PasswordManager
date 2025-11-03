//
// Created by Kya Toms on 9/30/25.
//

#include "Account.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Account::Account() : username(""), password() {}

Account::Account(const string& user, const Password& pass) : username(user), password(pass) {}

//Getters
string Account::getUsername() const
{
    return username;
}

Password Account::getPassword() const
{
    return password;
}

//Setters
void Account::setUsername(const string& user)
{
    username = user;
}

void Account::setPassword(const Password& pass)
{
    password = pass;
}

void Account::displayAccountInfo() const
{
    cout << "Username: " << username << endl;
    cout << "Password: " << password.getValue() << endl;
}

void Account::saveToStream(ofstream& out) const
{
    out << username << " " << password.getValue() << "\n";
}

Account Account::loadFromStream(ifstream& in)
{
    string user, pass;
    if (in >> user >> pass)
    {
        return Account(user, Password(pass));
    }
    return Account();
}





