#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <string>

#include "UserManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;

public:
    PersonalBudget(string fileNameWithUsers)
        : userManager(fileNameWithUsers) {};

    void registerUser();
    void showAllUsers();
    void loginUser();
    void logoutUser();
    void changePassword();
};
#endif // PERSONALBUDGET_
