# Password Manager
## Kya Toms
ktoms@uvm.edu 

**Languages Used**: 
C++, Python

This project is a menu-based password manager that allows users to generate, store, and evaluate their passwords. 
Users can add passwords manually, generate random passwords at different complexity levels, check password strength (using entropy), validate 
against a password policy that I implemented into main, and list stored passwords. Stored passwords are displayed in a masked
format (****) with an option to reveal them. Users can create an Account, where one can create a username and password
that is then printed to a file to be stored. User passwords to login are hashed in `hashing.py` a python file that uses a built-in hashing library. 
Users can also back-up their password manager list to a different file named with their username. These passwords are encrypted with a 
double columnar transposition cipher. The user must provide two keywords when saving those passwords (and must provide them again when looking to 
decrypt the list. Additionally, there is  an Admin User that currently has a default login that is built into main. Admin's can print a list of all current users
and access a masked list of their passwords in the manager. 

### Current Bugs
Need to call decrypt back. 

### Future/In-progress work
Adding API-based malware and leak checks using VirusTotal for stored Usernames and passwords for theory. 
