//
// Created by Kya Toms on 9/8/25.
//
#include <iostream>
#include <cstdlib>
#include "Password.h"
#include "PasswordPolicy.h"
#include "PasswordGenerator.h"
#include "PasswordManager.h"
#include "Account.h"
#include "UserAccount.h"
#include "AdminAccount.h"
using namespace std;

const string python = "python3";

//Hashes password with python script
string hashPasswordPython(const string& pw) 
{
    string command = python + " hashing.py " + pw + " > temp_hash.txt";
    system(command.c_str());

    ifstream fin("temp_hash.txt");
    string hashed;
    getline(fin, hashed);
    fin.close();
    return hashed;
}

void saveAllUsers (const vector<UserAccount>& allUsers)
{
    ofstream fout("usersM3OEP.txt");
    for (const auto& u : allUsers)
    {
        fout << u.getUsername() << " " << u.getPassword().getValue() << "\n";
    }
}

vector<UserAccount> loadAllUsers()
{
    vector<UserAccount> users;
    ifstream fin("usersM3OEP.txt");
    string uname, pw;
    while (fin >> uname >> pw)
    {
        UserAccount newUser(uname, Password(pw));
        users.push_back(newUser);
        // also load that user's password manager from their file
        users.back().loadManager(pw);
    }
    return users;
}

int main() {
    PasswordGenerator generator;
    PasswordPolicy policy(8, true, true); //Minimum length 8, must have number and symbol

    vector<UserAccount> allUsers = loadAllUsers();
    AdminAccount admin("admin", Password("admin123")); //Default admin

    while (true)
    {
        cout <<"\n===== Main Menu =====\n";
        cout << "1. Create User Account\n";
        cout << "2. Login as User\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";

        int mainChoice;
        cout << "\nChoose an option (1-4): ";
        cin >> mainChoice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // reset fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            continue; // go back to the top of the loop
        }

        if (mainChoice == 4)
        {
            cout << "Saving users...\n";
            saveAllUsers(allUsers);
            cout << "Goodbye!\n";
            break;
        }

        if (mainChoice == 1)
        {
            string uname, pw;
            cout << "Enter new username: ";
            cin >> uname;
            cout << "Enter password: ";
            cin >> pw;

            string hashedPw = hashPasswordPython(pw);
    

            UserAccount newUser(uname, Password(hashedPw));
            allUsers.push_back(newUser);
            newUser.saveManager();
            saveAllUsers(allUsers);
            cout << "User account created.\n";
        }

        else if (mainChoice == 2)
        {
            string uname, pw;
            cout << "Username: ";
            cin >> uname;
            cout << "Password: ";
            cin >> pw;

            string hashedPw = hashPasswordPython(pw);

            // find user
            UserAccount* currentUser = nullptr;
            for (auto& u : allUsers)
            {
                if (u.getUsername() == uname && u.getPassword() == Password(hashedPw))
                {
                    currentUser = &u;
                    break;
                }
            }

            if (!currentUser)
            {
                cout << "Login failed.\n";
                continue;
            }

            cout << "Welcome, " << uname << "!\n";
            currentUser->loadManager(hashedPw);
            PasswordManager& manager = currentUser->getManager();

            while (true)
            {
                cout << "\n===== Password Manager Menu =====\n";
                cout << "1. Add password manually\n";
                cout << "2. Generate password\n";
                cout << "3. List all passwords\n";
                cout << "4. Test password strength\n";
                cout << "5. Validate with password policy\n";
                cout << "6. Save manager to file\n";
                cout << "7. Logout\n";

                int choice;
                cout << "\nChoose an option (1-7): ";
                cin >> choice;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.\n";
                    continue;
                }

                if (choice == 7)
                {
                    cout << "Logging out.\n";
                    break;
                }

                if (choice == 1)
                {
                    string pw;
                    cout << "Enter a password: ";
                    cin >> pw;
                    manager.addPassword(pw);
                    cout << "Password added.\n";
                }
                else if (choice == 2)
                {
                    cout << "Select level: 1 = SIMPLE, 2 = MEDIUM, 3 = COMPLEX: ";
                    int lvl;
                    while (!(cin >> lvl) || lvl < 1 || lvl > 3)
                    {
                        cout << "Invalid choice. Enter 1, 2, or 3: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    Level level = (lvl == 1 ? Level::SIMPLE :
                                   lvl == 2 ? Level::MEDIUM : Level::COMPLEX);

                    string pw = generator.generate(level);
                    cout << "Generated password: " << pw << endl;

                    char ynChoice;
                    cout << "Add it to your manager? y/n: ";
                    cin >> ynChoice;
                    if (ynChoice == 'y' || ynChoice == 'Y')
                    {
                        manager.addPassword(pw);
                        cout << "Password added.\n";
                    }
                }
                else if (choice == 3)
                {
                    cout << "Passwords currently in password manager:\n";
                    vector<string> pwds = manager.listPasswords();

                    if (pwds.empty())
                    {
                        cout << "(No passwords stored)\n";
                    }
                    else
                    {
                        // Masked output
                        for (int i = 0; i < pwds.size(); i++)
                        {
                            cout << i + 1 << ". " << Password(pwds[i]) << endl;
                        }

                        char reveal;
                        while (true)  // loop until valid input
                        {
                            cout << "Would you like to reveal the actual passwords? y/n: ";
                            cin >> reveal;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover input

                            if (reveal == 'y' || reveal == 'Y')
                            {
                                for (int i = 0; i < pwds.size(); i++)
                                {
                                    cout << i + 1 << ". " << pwds[i] << endl;
                                }
                                break;
                            }
                            else if (reveal == 'n' || reveal == 'N')
                            {
                                cout << "Passwords remain masked.\n";
                                break;
                            }
                            else
                            {
                                cout << "Invalid input. Please enter y or n.\n";
                            }
                        }
                    }
                }
                else if (choice == 4)
                {
                    string pw;
                    cout << "Enter a password: ";
                    cin >> pw;
                    cout << "Strength: " << Password(pw).checkStrength() << endl;
                }
                else if (choice == 5)
                {
                    string pw;
                    cout << "Enter a password: ";
                    cin >> pw;
                    cout << (policy.validate(pw) ?
                             "Password meets policy.\n" :
                             "Password does NOT meet policy.\n");
                }
                else if (choice == 6)
                {
                    if (currentUser->saveManager()) cout << "Saved.\n";
                    else cout << "Save failed.\n";
                }
            }
        }
        else if (mainChoice == 3) {
            string uname, pw;
            cout << "Admin username: ";
            cin >> uname;
            cout << "Admin password: ";
            cin >> pw;

            if (uname != admin.getUsername() || admin.getPassword().getValue() != pw)
            {
                cout << "Admin login failed.\n";
                continue;
            }

            cout << "Admin logged in.\n";
            while (true) {
                cout << "\n===== Admin Menu =====\n";
                cout << "1. List all users\n";
                cout << "2. Open user manager (read-only)\n";
                cout << "3. Logout\n";

                int ach;
                cin >> ach;
                if (ach == 3) break;

                if (ach == 1)
                {
                    if (allUsers.empty()) cout << "(No users)\n";
                    else
                    {
                        for (auto& u : allUsers) cout << u.getUsername() << endl;
                    }
                }
                else if (ach == 2)
                {
                    string uname;
                    cout << "Enter username: ";
                    cin >> uname;
                    for (auto& u : allUsers)
                    {
                        if (u.getUsername() == uname)
                        {
                            vector<string> pwds = u.getManager().listPasswords();
                            cout << uname << "'s passwords:\n";
                            for (int i = 0; i < pwds.size(); i++)
                                cout << i + 1 << ". " << Password(pwds[i]) << endl;
                        }
                    }
                }
            }
        }
    }
    }