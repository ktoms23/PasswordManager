//
// Created by Kya Toms on 9/30/25.
//

#include "AdminAccount.h"

AdminAccount::AdminAccount() : Account(), managedUsers() {}

AdminAccount::AdminAccount(const string& user, const Password& pass) : Account(user, pass), managedUsers() {}

void AdminAccount::addUser(const UserAccount& userAccount)
{
    managedUsers.push_back(userAccount);
}

vector<string> AdminAccount::listUsers() const
{
    vector<string> usernames;
    for (const auto& user : managedUsers)
    {
        usernames.push_back(user.getUsername());
    }
    return usernames;
}

bool AdminAccount::openUserManager(const string& username, PasswordManager& pm)
{
    string filename = username + ".txt";
    pm.loadFromFile(filename);
    return true;
}




