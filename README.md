# M3OEP-ktoms
# Open Project
### Kya Toms
This project is a menu-based password manager that allows users to generate, store, and evaluate their passwords. 
Users can add passwords manually, generate random passwords at different complexity levels, check password strength, validate 
against a password policy that I implemented into main, and list stored passwords. Stored passwords are displayed in a masked
format (****) with an option to reveal them. Users can create an Account, where one can create a username and password
that is then printed to a file to be stored. In Module 3, I wrote hashing.py a python file that uses a built in hashing library to hash the passwords for accounts. This way users can log in even after local memory has been reset. They can also backup their password manager list to a different file named with their username. Additionally, there is  an Admin User that currently has a default login that is built into main. Admin's can print a list of all current users
and access a masked list of their passwords in the manager. 
The program is organized into multiple classes:
* `Password`: Represents a single password, calculates its entropy, evaluates its strength and provides custom operators for comparison 
and secure output.
* `PasswordManager`: Manages a collection of stored passwords (add, list).
* `PasswordPolicy`: Defines and validates rules for password requirements (minimum length, digit/symbol requirements).
* `PasswordGenerator`: Generates random passwords at different complexity levels (simple, medium, complex).
* `Account`: Represents a single Account with a username and password, with functionality to display account info
* `UserAccount`: "IS-A" Account that "HAS_A" PasswordManager to manage stored passwords
* `AdminAccount`: "IS_A" Account "HAS-A" collection of User Accounts it can manage. 

## Module 3 Concepts Used:
* The main logic of the program is written in C++, Python is also used in order to hash user account passwords for security.
* Python is a good choice for hashing passwords as it has built in cryptographic and hashing libraries.
* C++ is the primary language and it calls Python when hashing passwords. It occurs in the function `hashPasswordPython` it passes the password as a command-line argument. The Python script hashes the password and outputs the result to a text file `temp_hash.txt`, which the C++ program then reads in. 

## Bugs
* There are no known bugs at the time of submission

## Future Work
With more time there are several things I would like to implement into my project. Currently for AdminAccount, admins can see User's listed passwords, but only in masked format. The passwords for the user logins are now hashed, however there is no added security to the passwords user's choose to save. I would like to implement an encryption/decryption for this. 

## Citations 

- **For calculating entropy**  
  R. Koch, *What is password entropy?*, Proton, Oct. 05, 2023.  
    [https://proton.me/blog/what-is-password-entropy](https://proton.me/blog/what-is-password-entropy)  

- **For `isalnum`**  
*std::isalnum - cppreference.com*, 2024.  
[https://en.cppreference.com/w/cpp/string/byte/isalnum.html](https://en.cppreference.com/w/cpp/string/byte/isalnum.html) (accessed Sep. 14, 2025)  

- **For Random Number Generator**  
  *Pseudo-random number generation - cppreference.com*, 2025.  
  [https://en.cppreference.com/w/cpp/numeric/random.html](https://en.cppreference.com/w/cpp/numeric/random.html)

- **Using cignore**

  Ryan, *Understanding and Using cin.ignore() in C++* Medium, Oct. 06, 2024.

  [https://medium.com/@ryan_forrester_/understanding-and-using-cin-ignore-in-c-09ead6df053f](https://medium.com/@ryan_forrester_/understanding-and-using-cin-ignore-in-c-09ead6df053f)

- **Using hashlib**

  *hashlib module in Python* GeeksforGeeks, Jul. 23 2025.

  [https://www.geeksforgeeks.org/python/hashlib-module-in-python/?utm_source=chatgpt.com](https://www.geeksforgeeks.org/python/hashlib-module-in-python/?utm_source=chatgpt.com)

## Grade I believe I should earn:
**Main program complexity and usability** 
I believe I should earn a 40 as my project is a fully interactive meny passed program that implements all the concepts from Module 3.
The `main.cpp` is fully interactive and validates user input when it is out of range or not an integer and reprompts users. I believe my 
seven classes combined meet the expected complexity for a Module 03 open-ended project. 

**The use of multiple languages** 
I believe I should earn a 20 as my program integrates C++ and Python in a functional way. The primary program is written in C++ for its performance and Python is used for hashing passwords through the built-in hashlib library.

**Choice of languages**
I believe I should earn 20 points as creating a hashing function in python plays to the strength of the languages. The built in library allows for hashing without manual implementations in C++

**Command line arguments and file I/O**
I believe I should earn 20 points because information is meaningfully passed between C++ and Python using both command-line arguments and file I/O/ in `hashPasswordPython()` the C++ program executes the Python program `hashing.py` through a system call. It sends the password to Python as a command-line argument. 
It outputs the hashed password into a text file, which C++ then reads back in. 

**Concepts: Is-A and Has-A**
I believe I should receive a total of 80 points for this category as I created 2 Is-A relationships and 2 Has-A relationships. 
* IS-A Relationships
  * `UserAccount` IS-A Account
  * `AdminAccount` IS-A Account
* HAS-A Relationships
  * `UserAccount` HAS-A PasswordManager
  * `AdminAccount` HAS-A vector of UserAccount(s)

**Concepts: File input/output**
I believe I should receive a total of 40 points in this category as I utilize several examples for file input and output in my project. 
 * Output -> "usersM20EP.txt" usernames and passwords of Users 
  * Input -> of "usersM20EP.txt" via loadAllUsers()
  * Output -> "'username'.txt" each individual user's passwords to their document
  * Input -> of "'username'.txt" to list individual user's saved passwords
