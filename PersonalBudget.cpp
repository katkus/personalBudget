#include "PersonalBudget.h"

void PersonalBudget::registerUser() {
    userManager.registerUser();
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

char PersonalBudget::selectOptionFromMainMenu() {
    char choice;

    system("clear");//Windows system("cls")
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char PersonalBudget::selectOptionFromBudgetMenu() {
    char choice;

    system("clear");//Windows system("cls")
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
