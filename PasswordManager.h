//
// Created by Kya Toms on 9/8/25.
//
#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
#include <string>
#include <vector>
using namespace std;

/*
*This class represents a manager of different Passwords where the user can add a password and list the current passwords in memory.
 */

class PasswordManager
{
private:
    vector<string> passwords;
public:
    /*
     * Constructor
     */
    PasswordManager();

    /*
     * Adds a password to the vector passwords
     * @param password- the password string to add
     */
    void addPassword(const string &password);


    /*
     * Lists the passwords in the passwords vector
     * @return vector <string> list of password strings
     */
    vector<string> listPasswords() const;

    /*
     * Gives users ability to save their manager to a file and load it back
     */
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};



#endif //PASSWORDMANAGER_H
