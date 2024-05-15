#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");

    //personalBudget.registerUser();
    //personalBudget.showAllUsers();
    personalBudget.loginUser();


    return 0;
}
