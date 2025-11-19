//
// Created by Kya Toms on 9/8/25.
//
#include "PasswordGenerator.h"
#include <ctime> //For seeding the random number generator
using namespace std;

//Constructor seeds random generator with current time
PasswordGenerator::PasswordGenerator() : randomNum(time(nullptr)) {}

string PasswordGenerator::generate(Level level)
{
    string chars;
    int length;

    //Level determines character set and length
    if (level == Level::SIMPLE)
    {
        chars = lowercase;
        length = 6;
    }
    else if (level == Level::MEDIUM)
    {
        chars = lowercase + uppercase + numbers;
        length = 10;
    }
    else if (level == Level::COMPLEX)
    {
        chars = lowercase + uppercase + numbers + symbols;
        length = 14;
    }

    //Generate password
    string password;

    for (int i = 0; i < length; i++)
    {
        int index = randomNum() % chars.size();
        password += chars[index];
    }

    return password;
}


