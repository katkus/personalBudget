#include "PersonalBudget.h"

void PersonalBudget::registerUser() {
    userManager.registerUser();
}
void PersonalBudget::showAllUsers() {
    userManager.showAllUsers();
}
void PersonalBudget::loginUser() {
    userManager.loginUser();
        if (userManager.isUserLoggedIn()) {
        budgetManager= new BudgetManager (FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getLoggedInUserId());
    }
}
void PersonalBudget::logoutUser() {
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}
void PersonalBudget::changePassword() {
    userManager.changePassword();
}
void PersonalBudget::addIncome() {
    if(userManager.isUserLoggedIn()) {
        budgetManager->addIncome();
    } else {
        cout << "Aby dodac zarobek, nalezy najpierw sie zalogowac." << endl;
        system("read"); // Windows system("pause")
    }
}
void PersonalBudget::addExpense() {
    if(userManager.isUserLoggedIn()) {
        budgetManager->addExpense();
    } else {
        cout << "Aby dodac zarobek, nalezy najpierw sie zalogowac." << endl;
        system("read"); // Windows system("pause")
    }
}
