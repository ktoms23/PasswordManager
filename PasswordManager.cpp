//
// Created by Kya Toms on 9/8/25.
//
#include "PasswordManager.h"
#include <fstream>
#include <iostream>
using namespace std;


PasswordManager::PasswordManager() {}

void PasswordManager::addPassword(const string &password)
{
    passwords.push_back(password);
}

vector<string> PasswordManager::listPasswords() const
{
    return passwords;
}

void PasswordManager::saveToFile(const string& filename) const
{
    ofstream out(filename);
    for (const auto& pw : passwords)
    {
        out << pw << "\n";
    }
    out.close();
}

void PasswordManager::loadFromFile(const string& filename)
{
    ifstream in(filename);
    string pw;
    passwords.clear();
    while (getline(in, pw))
    {
        if (!pw.empty())
        {
            passwords.push_back(pw);
        }
    }
    in.close();
}






