#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib> //windows.h
#include <fstream>
#include <sstream>


#include "User.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;

public:
    UserManager() {
        loggedInUserId = 0;
    };
    void registerUser();
} ;
#endif // USERMANAGER_H
