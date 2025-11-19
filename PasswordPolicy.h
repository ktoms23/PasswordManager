//
// Created by Kya Toms on 9/8/25.
//
#ifndef PASSWORDPOLICY_H
#define PASSWORDPOLICY_H
#include <string>
#include <ostream>
#include "Password.h"
using namespace std;

/*
This class represents the policies for passwords and their requirements
 */

class PasswordPolicy
{
  private:
    int minLength; //Minimum length of the password
    bool requiresSymbol; //Password requires a symbol
    bool requiresNumber; //Password requires a number

  public:
    /*
     * Constructor
     * @param minLen Minimum length required
     * @param symbol Whether a symbol is required
     * @param number Whether a number is required
     */
    PasswordPolicy(int minLen = 8, bool symbol = true, bool number = true);

    /*
     * Validates a password against the policy
     * @param pw The password to check
     * @return true if valid, false otherwise
     */
    bool validate(const Password& pw) const;

    //Getters
    int getMinLength() const;
    bool getRequiresSymbol() const;
    bool getRequiresNumber() const;

    //Setters (for future?)
    void setMinLength(int minLen);
    void setRequiresSymbol(bool symbol);
    void setRequiresNumber(bool number);

};
#endif //PASSWORDPOLICY_H
