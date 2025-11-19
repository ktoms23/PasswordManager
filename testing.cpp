#include "Account.h"
#include "UserAccount.h"
#include "AdminAccount.h"
#include "Password.h"
#include "PasswordGenerator.h"
#include "PasswordPolicy.h"
#include <iostream>
using namespace std;

//Account tests
bool account_tests();
bool test_Account_Constructors();
bool test_Account_GettersSetters();
bool test_Account_Display();

//UserAccount tests
bool useraccount_tests();
bool test_UserAccount_Constructors();
bool test_UserAccount_PasswordManager();

//AdminAccount tests
bool adminaccount_tests();
bool test_AdminAccount_Constructors();
bool test_AdminAccount_UserManagement();

//Password tests
bool password_tests();
bool test_Password_Constructors();
bool test_Password_Getters();
bool test_Password_Strength();
bool test_Password_Operators();

//PasswordGenerator tests
bool passwordgenerator_tests();
bool test_PasswordGenerator_Constructors();
bool test_PasswordGenerator_Simple();
bool test_PasswordGenerator_Medium();
bool test_PasswordGenerator_Complex();

//PasswordManager tests
bool passwordmanager_tests();
bool test_PasswordManager_Constructors();
bool test_PasswordManager_AddPassword();
bool test_PasswordManager_ListPasswords();

//PasswordPolicy tests
bool passwordpolicy_tests();
bool test_PasswordPolicy_Constructors();
bool test_PasswordPolicy_Validation();

int runTests()
{
    if (account_tests())
    {
        cout << "PASSED all Account tests" << endl;
    }
    if (useraccount_tests())
    {
        cout << "PASSED all UserAccount tests" << endl;
    }
    if (adminaccount_tests())
    {
        cout << "PASSED all AdminAccount tests" << endl;
    }
    if (password_tests())
    {
        cout << "PASSED all Password tests" << endl;
    }
    if (passwordgenerator_tests())
    {
        cout << "PASSED all PasswordGenerator tests" << endl;
    }
    if (passwordmanager_tests())
    {
        cout << "PASSED all PasswordManager tests" << endl;
    }
    if (passwordpolicy_tests())
    {
        cout << "PASSED all PasswordPolicy tests" << endl;
    }
}

bool account_tests()
{
    bool passed = true;
    if (test_Account_Constructors()){}
    if (test_Account_GettersSetters()){}
    if (test_Account_Display()){}

    return passed;
}

bool useraccount_tests()
{
    bool passed = true;
    if (test_UserAccount_Constructors()){}
    if (test_UserAccount_PasswordManager()){}

    return passed;
}

bool adminaccount_tests()
{
    bool passed = true;
    if (test_AdminAccount_Constructors()) {}
    if (test_AdminAccount_UserManagement()) {}

    return passed;
}

bool password_tests()
{
    bool passed = true;
    if (test_Password_Constructors()){}
    if (test_Password_Getters()) {}
    if (test_Password_Strength()) {}
    if (test_Password_Operators()) {}

    return passed;
}

bool passwordgenerator_tests()
{
    bool passed = true;
    if (test_PasswordGenerator_Constructors()){}
    if (test_PasswordGenerator_Simple()) {}
    if (test_PasswordGenerator_Medium()) {}
    if (test_PasswordGenerator_Complex()) {}

    return passed;
}

bool passwordmanager_tests()
{
    bool passed = true;
    if (test_PasswordManager_Constructors()) {}
    if (test_PasswordManager_AddPassword()) {}
    if (test_PasswordManager_ListPasswords()) {}

    return passed;
}

bool passwordpolicy_tests()
{
    bool passed = true;
    if (test_PasswordPolicy_Constructors()) {}
    if (test_PasswordPolicy_Validation()) {}

    return passed;
}





bool test_Account_Constructors()
{
    bool passed = true;

    Account a1;
    if (a1.getUsername() != "")
    {
        passed = false;
        cout << "FAILED default constructor: username not empty" << endl;

    }

    Password p1("abc123");
    Account a2("Kya", p1);
    if (a2.getUsername() != "Kya")
    {
        passed = false;
        cout << "FAILED constructor: username not correct" << endl;
    }
    if (a2.getPassword().getValue() != "abc123")
    {
        passed = false;
        cout << "FAILED constructor: password not correct" << endl;
    }

    return passed;
}

bool test_Account_GettersSetters()
{
    bool passed = true;

    Account a;
    a.setUsername("testUser");
    if (a.getUsername() != "testUser")
    {
        passed = false;
        cout << "FAILED setter/getter username test" << endl;
    }

    Password p("password1");
    a.setPassword(p);
    if (a.getPassword().getValue() != "password1")
    {
        passed = false;
        cout << "FAILED setter/getter password test" << endl;
    }

    return passed;
}

bool test_Account_Display()
{
    bool passed = true;

    Password p ("secret");
    Account a("Bob", p);

    if (a.getUsername() != "Bob")
    {
        passed = false;
        cout << "FAILED account display: username not correct" << endl;
    }

    if (a.getPassword().getValue() != "secret")
    {
        passed = false;
        cout << "FAILED account display: password not correct" << endl;
    }

    return passed;
}

//UserAccount Tests

bool test_UserAccount_Constructors()
{
    bool passed = true;
    UserAccount ua;
    if (ua.getUsername() != "")
    {
        passed = false;
        cout << "FAILED UserAccount default constructor" << endl;
    }

    Password p("password");
    UserAccount ua2("Bobby", p);
    if (ua2.getUsername() != "Bobby")
    {
        passed = false;
        cout << "FAILED UserAccount constructor: username not correct" << endl;
    }
    if (ua2.getPassword().getValue() != "password")
    {
        passed = false;
        cout << "FAILED UserAccount constructor: password not correct" << endl;
    }

    return passed;
}

bool test_UserAccount_PasswordManager()
{
    bool passed = true;

    UserAccount ua("exampleUser", Password("pw1"));
    ua.getManager().addPassword("pw2");
    ua.getManager().addPassword("pw3");

    vector<string> pwds = ua.getManager().listPasswords();
    if (pwds.size() != 2)
    {
        passed = false;
        cout << "FAILED UserAccount PasswordManager: wrong number of passwords" << endl;
    }
    if (pwds[0] != "pw2" || pwds[1] != "pw3")
    {
        passed = false;
        cout << "FAILED UserAccount PasswordManager: password values not correct" << endl;
    }

    return passed;
}

//AdminAccount Tests

bool test_AdminAccount_Constructors()
{
    bool passed = true;

    AdminAccount ad1;
    if (ad1.getUsername() != "")
    {
        passed = false;
        cout << "FAILED AdminAccount default constructor: username not empty" << endl;
    }

    Password p("admin123");
    AdminAccount ad2("Admin", p);
    if (ad2.getUsername() != "Admin")
    {
        passed = false;
        cout << "FAILED AdminAccount constructor: username not correct" << endl;
    }
    if (ad2.getPassword().getValue() != "admin123")
    {
        passed = false;
        cout << "FAILED AdminAccount constructor: password not correct" << endl;
    }

    return passed;
}

bool test_AdminAccount_UserManagement()
{
    bool passed = true;

    AdminAccount admin("Employee", Password("france"));
    UserAccount ua1("Thomas", Password("thomaspwd"));
    UserAccount ua2("Maggie", Password("maggiepwd"));

    admin.addUser(ua1);
    admin.addUser(ua2);

    vector<string> usernames = admin.listUsers();

    if (usernames.size() != 2)
    {
        passed = false;
        cout << "FAILED AdminAccount user management: wrong number of users" << endl;
    }
    if (usernames[0] != "Thomas" || usernames[1] != "Maggie")
    {
        passed = false;
        cout << "FAILED AdminAccount user management: usernames not correct" << endl;
    }

    return passed;
}

//Password tests

bool test_Password_Constructors()
{
    bool passed = true;

    Password p1;
    if (p1.getValue() != "" || p1.getLength() != 0)
    {
        passed = false;
        cout << "FAILED default constructor test" << endl;
    }

    Password p2("hello");
    if (p2.getValue() != "hello" || p2.getLength() != 5)
    {
        passed = false;
        cout << "FAILED non-default constructor test" << endl;
    }

    return passed;
}

bool test_Password_Getters()
{
    bool passed = true;

    Password p("abc123!");
    if (p.getLength() != 7)
    {
        passed = false;
        cout << "FAILED getLength test" << endl;
    }
    if (p.getValue() != "abc123!")
    {
        passed = false;
        cout << "FAILED getValue test" << endl;
    }
    if (p.getEntropy() <= 0)
    {
        passed = false;
        cout << "FAILED getEntropy test" << endl;
    }

    return passed;
}

bool test_Password_Strength()
{
    bool passed = true;

    Password weak("a");  // very low entropy
    if (weak.checkStrength() != Strength::WEAK)
    {
        passed = false;
        cout << "FAILED weak strength test" << endl;
    }

    Password medium("abcdef12345"); // moderate entropy
    if (medium.checkStrength() != Strength::MEDIUM)
    {
        passed = false;
        cout << "FAILED medium strength test" << endl;
    }

    Password strong("Abc123!@#XYZ"); // high entropy
    if (strong.checkStrength() != Strength::STRONG)
    {
        passed = false;
        cout << "FAILED strong strength test" << endl;
    }

    return passed;
}

bool test_Password_Operators()
{
    bool passed = true;

    Password p1("secret");
    Password p2("secret");
    Password p3("different");

    if (!(p1 == p2))
    {
        passed = false;
        cout << "FAILED equality operator test" << endl;
    }

    if (p1 == p3)
    {
        passed = false;
        cout << "FAILED inequality operator test" << endl;
    }

    return passed;
}

//Password generator tests

bool test_PasswordGenerator_Constructors()
{
    bool passed = true;

    PasswordGenerator pg;
    string pw = pg.generate(Level::SIMPLE);

    if (pw.empty())
    {
        passed = false;
        cout << "FAILED PasswordGenerator constructor: generated empty password" << endl;
    }

    return passed;
}

bool test_PasswordGenerator_Simple()
{
    bool passed = true;

    PasswordGenerator pg;
    string pw = pg.generate(Level::SIMPLE);

    if (pw.size() != 6)
    {
        passed = false;
        cout << "FAILED SIMPLE generation: length not 6" << endl;
    }

    return passed;
}

bool test_PasswordGenerator_Medium()
{
    bool passed = true;

    PasswordGenerator pg;
    string pw = pg.generate(Level::MEDIUM);

    if (pw.size() != 10)
    {
        passed = false;
        cout << "FAILED MEDIUM generation: length not 10" << endl;
    }

    return passed;
}

bool test_PasswordGenerator_Complex()
{
    bool passed = true;

    PasswordGenerator pg;
    string pw = pg.generate(Level::COMPLEX);

    if (pw.size() != 14)
    {
        passed = false;
        cout << "FAILED COMPLEX generation: length not 14" << endl;
    }

    return passed;
}

//Test password manager

bool test_PasswordManager_Constructors()
{
    bool passed = true;

    PasswordManager pm;
    vector<string> pwList = pm.listPasswords();

    if (!pwList.empty())
    {
        passed = false;
        cout << "FAILED PasswordManager default constructor: passwords not empty" << endl;
    }

    return passed;
}

bool test_PasswordManager_AddPassword()
{
    bool passed = true;

    PasswordManager pm;
    pm.addPassword("abc123");

    vector<string> pwList = pm.listPasswords();

    if (pwList.size() != 1)
    {
        passed = false;
        cout << "FAILED addPassword: size not 1" << endl;
    }

    if (pwList[0] != "abc123")
    {
        passed = false;
        cout << "FAILED addPassword: password not stored correctly" << endl;
    }

    return passed;
}

bool test_PasswordManager_ListPasswords()
{
    bool passed = true;

    PasswordManager pm;
    pm.addPassword("pw1");
    pm.addPassword("pw2");
    pm.addPassword("pw3");

    vector<string> pwList = pm.listPasswords();

    if (pwList.size() != 3)
    {
        passed = false;
        cout << "FAILED listPasswords: size not 3" << endl;
    }

    if (pwList[0] != "pw1" || pwList[1] != "pw2" || pwList[2] != "pw3")
    {
        passed = false;
        cout << "FAILED listPasswords: passwords not in correct order" << endl;
    }

    return passed;
}

bool test_PasswordPolicy_Constructors()
{
    bool passed = true;

    PasswordPolicy p1;
    if (p1.getMinLength() != 8)
    {
        passed = false;
        cout << "FAILED PasswordPolicy default constructor: minLength not 8" << endl;
    }
    if (!p1.getRequiresSymbol())
    {
        passed = false;
        cout << "FAILED PasswordPolicy default constructor: requiresSymbol not true" << endl;
    }
    if (!p1.getRequiresNumber())
    {
        passed = false;
        cout << "FAILED PasswordPolicy default constructor: requiresNumber not true" << endl;
    }

    PasswordPolicy p2(10, false, true);
    if (p2.getMinLength() != 10)
    {
        passed = false;
        cout << "FAILED PasswordPolicy constructor: minLength not 10" << endl;
    }
    if (p2.getRequiresSymbol())
    {
        passed = false;
        cout << "FAILED PasswordPolicy constructor: requiresSymbol should be false" << endl;
    }
    if (!p2.getRequiresNumber())
    {
        passed = false;
        cout << "FAILED PasswordPolicy constructor: requiresNumber should be true" << endl;
    }

    return passed;
}

bool test_PasswordPolicy_Validation()
{
    bool passed = true;

    PasswordPolicy p(6, true, true); // needs 6+ chars, symbol, number

    Password pw1("abc"); // too short
    if (p.validate(pw1))
    {
        passed = false;
        cout << "FAILED PasswordPolicy validate: accepted too short password" << endl;
    }

    Password pw2("abcdef"); // no number, no symbol
    if (p.validate(pw2))
    {
        passed = false;
        cout << "FAILED PasswordPolicy validate: accepted password without number/symbol" << endl;
    }

    Password pw3("abc123"); // no symbol
    if (p.validate(pw3))
    {
        passed = false;
        cout << "FAILED PasswordPolicy validate: accepted password without symbol" << endl;
    }

    Password pw4("abc123!"); // valid
    if (!p.validate(pw4))
    {
        passed = false;
        cout << "FAILED PasswordPolicy validate: rejected valid password" << endl;
    }

    return passed;
}





