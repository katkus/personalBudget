#include "BudgetManager.h"

void BudgetManager::addIncome() {
    Earning income;

    system("clear");//Windows system("cls")
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = addEarningDetails(INCOME);
    incomes.push_back(income);

    if(incomeFile.addEarningToFile(income, INCOME) == true) {
        cout << "Nowy przychod zostal dodany do pliku." << endl;
    } else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;

    system("read"); // Windows system("pause")
}

void BudgetManager::addExpense() {
    Earning expense;

    system("clear");//Windows system("cls")
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = addEarningDetails(EXPENSE);
    expenses.push_back(expense);

    if(expenseFile.addEarningToFile(expense, EXPENSE) == true) {
        cout << "Nowy wydatek zostal dodany do pliku." << endl;
    } else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku." << endl;
    system("read"); // Windows system("pause")
}

Earning BudgetManager::addEarningDetails(const Type &type) {
    Earning earning;
    string typeDescription, date;
    char choice;

    switch(type) {

    case INCOME:
        earning.setEarningId((incomeFile.getLastId()+1));
        typeDescription = "przychod";
        break;
    case EXPENSE:
        earning.setEarningId((expenseFile.getLastId()+1));
        typeDescription = "wydatek";
        break;
    }

    earning.setUserId(LOGGED_IN_USER_ID);

    choice = selectOptionFromDateMenu();

    switch (choice) {

    case '1':
        date = dateMethods.getTimeFromSystem();
        break;
    case '2':
        do {
            system("clear");//Windows system("cls")
            cout << "Prosze o wpisanie daty w formacie rrrr-mm-dd. Zostanie dodany " << typeDescription << " do Budzetu. Data musi miescic sie w zakresie czasowym od 2000-01-01 do maksymalnie ostatniego dnia biezacego miesiaca." << endl << endl;
            date = AuxiliaryMethods::loadLine();
            if (dateMethods.checkFormatDateIsCorrect(date) == false)
                cout << "Niepoprawny format daty lub niepoprawnie podany zakres czasowy." << endl;
        } while (dateMethods.checkFormatDateIsCorrect(date)== false);
        break;
    case '9':
        exit(0);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("read"); // Windows system("pause")
        break;
    }
    earning.setDate(AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::changeDateWithHypenToDateWithoutHyphen(date)));
    system("clear");//Windows system("cls")
    cout << "Prosze o wpisanie czego dotyczy " << typeDescription << ": " << endl;
    earning.setItem(AuxiliaryMethods::loadLine());

    cout << "Prosze o wpisanie wielkosci z dokladnoscia do dwoch miejsc dziesietnych w zlotych: " << endl;
    earning.setAmount(AuxiliaryMethods::replaceCommaToDot(AuxiliaryMethods::loadLine()));

    return earning;
}

char BudgetManager::selectOptionFromDateMenu() {
    char choice;

    cout << "Dotyczy dnia dzisiejszego czy chcesz dodac z inna data? " << endl;
    cout << "1 - Dzisiejsza data" << endl;
    cout << "2 - Inna data" << endl;
    cout << "9 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
