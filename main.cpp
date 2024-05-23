#include <iostream>

#include "BudgetManager.h"

using namespace std;

int main()
{
    BudgetManager budgetManager("incomes.xml", "expenses.xml", 1);

    //personalBudget.registerUser();
    //budgetManager.addIncome();
    //budgetManager.addExpense();
    budgetManager.displayCurrentMonthsBalanceSheet();
    //personalBudget.loginUser();
    //personalBudget.changePassword();
    //personalBudget.logoutUser();


    return 0;
}
