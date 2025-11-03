//
// Created by Kya Toms on 9/30/25.
//

#ifndef M2OEP_KTOMS_USERACCOUNT_H
#define M2OEP_KTOMS_USERACCOUNT_H

#include "Account.h"
#include "PasswordManager.h"
//User has a password manager
/**
 * A UserAccount is a child of Account class
 * A UserAccount Has-a PasswordManager to manage stored passwords
 */


class UserAccount : public Account
{
private:
    PasswordManager manager;
public:
    /**
     * Default Constructor
     * Effects: Initializes Account with empty username/password and creates empty PasswordManager
     */
    UserAccount();

    /**
     * Constructor
     * @param user the username
     * @param pass the password
     * Effects: Initializes Account with given username/password and creates empty PasswordManager
     */
    UserAccount(const string&user, const Password& pass);

    /**
     * Reference to the user's password manager
     * @return reference to PasswordManager
     */
    PasswordManager& getManager();

    /**
     * Allows user to save manager under their username and load it back
     */
    bool saveManager();
    bool loadManager(const string& inputPassword);
};


#endif //M2OEP_KTOMS_USERACCOUNT_H