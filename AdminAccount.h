//
// Created by Kya Toms on 9/30/25.
//

#ifndef M2OEP_KTOMS_ADMINACCOUNT_H
#define M2OEP_KTOMS_ADMINACCOUNT_H

#include "Account.h"
#include "UserAccount.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

/**
 *An AdminAccount is a child of Account
 *An AdminAccout HAS-a collection of UserAccounts it can manage.
 */
class AdminAccount : public Account
{
private:
    vector<UserAccount> managedUsers;

public:
    /**
     *Default Constructor
     *Effects: Initializes Account with empty username/password and list of managed users
     */
    AdminAccount();

    /**
     *Constructor
     *@param user the username
     *@param pass the password
     *Effects: Initializes Account with given username/password and en empty list of managed users
     */
    AdminAccount(const string& user, const Password& pass);

    /**
     *Adds a user to the admin's managed users
     *@param userAccount the UserAccount to add
     */
    void addUser(const UserAccount& userAccount);

    /**
     *Lists the usernames of managed users
     *@return vector<string> of usernames
     */
    vector<string> listUsers() const;

    /**
     *Allows Admin to access password manager of users
     */
    bool openUserManager(const string& username, PasswordManager&pm);

};


#endif //M2OEP_KTOMS_ADMINACCOUNT_H