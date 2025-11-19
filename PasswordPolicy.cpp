//
// Created by Kya Toms on 9/8/25.
//
#include "PasswordPolicy.h"
#include <cctype>
using namespace std;

PasswordPolicy::PasswordPolicy(int minLen, bool symbol, bool number)
    : minLength(minLen), requiresSymbol(symbol), requiresNumber(number) {}

bool PasswordPolicy::validate(const Password& pw) const
{
    string val = pw.getValue();

    if ((int)val.size() < minLength)
    {
        return false;
    }

    bool hasSymbol = false;
    bool hasNumber = false;

    for (char c : val)
    {
        if (isdigit(c))
        {
            hasNumber = true;
        }
        else if (!isalnum(c))
        {
            hasSymbol = true;
        }
    }

    if (requiresNumber && !hasNumber)
    {
        return false;
    }
    if (requiresSymbol && !hasSymbol)
    {
        return false;
    }

    return true;

}

//Getters
int PasswordPolicy::getMinLength() const
{
    return minLength;
}
bool PasswordPolicy::getRequiresSymbol() const
{
    return requiresSymbol;
}
bool PasswordPolicy::getRequiresNumber() const
{
    return requiresNumber;
}

//Setters (for future?)
void PasswordPolicy::setMinLength(int minLen)
{
    minLength = minLen;
}
void PasswordPolicy::setRequiresSymbol(bool symbol)
{
    requiresSymbol = symbol;
}
void PasswordPolicy::setRequiresNumber(bool number)
{
    requiresNumber = number;
}