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


public:

    void addIncome();
    void addExpense();
} ;
#endif // BUDGETMANAGER_H
