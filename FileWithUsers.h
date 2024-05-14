#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"

using namespace std;

class FileWithUsers : public XMLFile {

public:
    FileWithUsers(string fileNameWithUsers) : XMLFile(fileNameWithUsers) {};
    void addUserToFile (User &user);
    vector <User> loadUsersFromFile();
};
#endif // FILEWITHUSERS_H
