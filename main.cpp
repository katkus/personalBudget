#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");

    personalBudget.registerUser();
    personalBudget.registerUser();
    personalBudget.showAllUsers();


    return 0;
}
