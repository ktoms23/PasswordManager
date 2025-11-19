//
// Created by Kya Toms on 9/30/25.
//

#ifndef M2OEP_KTOMS_ACCOUNT_H
#define M2OEP_KTOMS_ACCOUNT_H
#include <string>
#include <ostream>
#include "Password.h"
using namespace std;

/*
*This class represents a singular Account that has a username and password.
*As well as functionality to display the account info
 */

class Account
{
private:
 string username; //Account's username
 Password password; //Account HAS-a Password

public:
 /*
  * Default Constructor
  * @effects Initializes username as empty and Password with its default constructor
  */
 Account();

 /*
 * Constructor
 * @param user the username string
 * @param pass the Password object
 * @effects Initializes account with a username and password
 */
 Account(const string& user, const Password& pass);

 //Getters
 string getUsername() const;
 Password getPassword() const;

 //Setters
 void setUsername(const string& user);
 void setPassword(const Password& pass);

 /*
  * Displays the Account username and password
  * @return Account username and password
  */
 void displayAccountInfo() const;

 void saveToStream(ofstream& out) const;
 static Account loadFromStream(ifstream& in);

};


#endif //M2OEP_KTOMS_ACCOUNT_H