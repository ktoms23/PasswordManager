//
// Created by Kya Toms on 9/8/25.
//
#ifndef PASSWORD_H
#define PASSWORD_H
#include <string>
#include <ostream>
using namespace std;

/*
*This class represents a singular Password and provides functionality
to evaluate its strength and calculate its entropy
 */

enum class Strength {WEAK, MEDIUM, STRONG};

//Overloads enum values so they print
ostream& operator<<(ostream& os, Strength s);

class Password
{
  private:
    string value; //The actual password string
    int length; //The length of the password

  public:
    /*
     * Default Constructor
     * @effects Initializes Password value as empty string and length = 0
     */
    Password();
    /*
     * Constructor
     * @param val The Password string
     * @effects Initializes Password value and stores its length
     */
    Password(string val);

    /*
     * Evaluates Password strength based on entropy
     * @return Strength value {WEAK, MEDIUM, STRONG}
     */
    Strength checkStrength() const;

    // Getters/
    double getEntropy() const;
    int getLength() const;
    string getValue() const;

    /*Overloaded Operators */

    //True if both passwords are equal, false otherwise
    friend bool operator==(const Password& lhs, const Password& rhs);

    //Reference to the output stream with with password value inserted
    friend ostream& operator<<(ostream& os, const Password& pw);




};

#endif //PASSWORD_H
