cmake_minimum_required(VERSION 3.15)
project(M3OEP-ktoms)

set(CMAKE_CXX_STANDARD 17)

add_executable(M3OEP-ktoms
        main.cpp
        Password.cpp
        PasswordPolicy.cpp
        PasswordGenerator.cpp
        PasswordManager.cpp
        testing.cpp
        Account.cpp
        Account.h
        UserAccount.cpp
        UserAccount.h
        AdminAccount.cpp
        AdminAccount.h
        hashing.py
)
add_executable(testing_file
        testing.cpp
        Password.cpp
        PasswordPolicy.cpp
        PasswordGenerator.cpp
        PasswordManager.cpp
        testing.cpp
        Account.cpp
        Account.h
        UserAccount.cpp
        UserAccount.h
        AdminAccount.cpp
        AdminAccount.h
)

