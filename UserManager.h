#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib> //windows.h
#include <fstream>
#include <sstream>

#include "User.h"
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
    void showAllUsers();
    void loginUser();
    void logoutUser();

} ;
#endif // USERMANAGER_H
