#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib> //windows.h
#include <fstream>
#include <sstream>


#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;

    User getNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:
    UserManager() {
        loggedInUserId = 0;
    };

    void registerUser();
    void showAllUsers();
} ;
#endif // USERMANAGER_H
