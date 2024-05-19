#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib> //windows.h
#include <algorithm>
#include <string>

#include "Earning.h"
#include "FileWithEarning.h"
#include "DateMethods.h"
#include "AuxiliaryMethods.h"
#include "Type.h"

using namespace std;

class BudgetManager {
    const int LOGGED_IN_USER_ID;
    vector <Earning> incomes;
    vector <Earning> expenses;
    FileWithEarning incomeFile;
    FileWithEarning expenseFile;
    DateMethods dateMethods;

    Earning addEarningDetails(const Type &type);
    char selectOptionFromDateMenu();


public:
    BudgetManager (string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId)
        : LOGGED_IN_USER_ID(loggedInUserId), incomeFile(fileNameWithIncomes), expenseFile(fileNameWithExpenses) {
        incomes = incomeFile.loadEarningOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = expenseFile.loadEarningOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
} ;
#endif // BUDGETMANAGER_H
