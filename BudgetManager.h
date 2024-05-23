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
    void sortDateIncomes();
    void sortDateExpenses();
    string displayEarning(int number, const Type &type);
    double calculateBalanceSheet(int startDate, int endDate, const Type& type);
    void displayCalculateBalanceSheet(int startDate, int endDate);


public:
    BudgetManager (string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId)
        : LOGGED_IN_USER_ID(loggedInUserId), incomeFile(fileNameWithIncomes), expenseFile(fileNameWithExpenses) {
        incomes = incomeFile.loadEarningOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = expenseFile.loadEarningOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    void displayCurrentMonthsBalanceSheet();
    void displayPreviousMonthsBalanceSheet();
    void displayBalanceSheetFromSelectedTimePeriod();
} ;
#endif // BUDGETMANAGER_H
