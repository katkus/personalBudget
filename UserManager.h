#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib> //windows.h
#include <fstream>
#include <sstream>

#include "User.h"
#include "BudgetManager.h"
#include "Earning.h"
#include "FileWithUsers.h"
#include "XMLFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {

    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User getNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:
    UserManager(string fileNameWithUsers) : fileWithUsers (fileNameWithUsers) {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void registerUser();
    void loginUser();
    void logoutUser();
    void changePassword();
    bool isUserLoggedIn();
    int getLoggedInUserId();

} ;
#endif // USERMANAGER_H
