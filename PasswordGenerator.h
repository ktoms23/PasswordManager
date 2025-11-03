//
// Created by Kya Toms on 9/8/25.
//
#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H
#include <random>
#include <string>
using namespace std;

/*
This class allows users to generate a password based on the complexity level that they indicate
 */

enum class Level {SIMPLE, MEDIUM, COMPLEX};

class PasswordGenerator
{
  private:
    mt19937 randomNum; //random number generator

    //Character sets
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string numbers = "0123456789";
    const string symbols = "!@#$%^&*()-_=+[]{};:,.<>?/";

  public:
    /*
     * Constructor
     */
    PasswordGenerator();

    /*
     * Generates a password based on complexity level
     * SIMPLE -> only lower case, length ~8
     * MEDIUM -> lowercase + numbers, length ~10
     * COMPLEX -> all character sets, length ~14
     */
    string generate(Level level);



};

#endif //PASSWORDGENERATOR_H
