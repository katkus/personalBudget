#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <string>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
        budgetManager = NULL;
    };
    ~PersonalBudget() {
        delete budgetManager;
        budgetManager = NULL;
    };

    void registerUser();
    void showAllUsers();
    void loginUser();
    void logoutUser();
    void changePassword();
    void addIncome();
    void addExpense();
};
#endif // PERSONALBUDGET_
