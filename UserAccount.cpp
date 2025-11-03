//
// Created by Kya Toms on 9/30/25.
//

#include "UserAccount.h"
#include <fstream>
#include <iostream>


UserAccount::UserAccount() : Account(), manager(){}

UserAccount::UserAccount(const string& user, const Password& pass) : Account(user, pass), manager() {}

PasswordManager& UserAccount::getManager()
{
    return manager;
}

bool UserAccount::saveManager()
{
    string filename = getUsername() + ".txt";
    manager.saveToFile(filename);
    return true;
}

bool UserAccount::loadManager(const string& inputPassword)
{
    if (inputPassword != getPassword().getValue())
    {
        return false;
    }
    string filename = getUsername() + ".txt";
    manager.loadFromFile(filename);
    return true;
}



