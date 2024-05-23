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

void BudgetManager::sortDateIncomes() {

    sort(incomes.begin(), incomes.end(), [](const Earning& lhs, const Earning& rhs) {
        return lhs.date < rhs.date;
    });
}

void BudgetManager::sortDateExpenses() {

    sort(expenses.begin(), expenses.end(), [](const Earning& lhs, const Earning& rhs) {
        return lhs.date < rhs.date;
    });
}

string BudgetManager::displayEarning(int number, const Type &type) {
    string amount;
    switch(type) {

    case INCOME:
        cout << "-------------------------------------------------------------" << endl;
        cout << "Numer ID: " << incomes[number].getEarningId() << endl;
        cout << "Data: ";
        dateMethods.displayDate(AuxiliaryMethods::changeDateWithoutHypenToDateWithHyphen(AuxiliaryMethods::convertIntToString(incomes[number].getDate())));
        cout << endl << "Opis: " << incomes[number].getItem() << endl;
        cout << "Wartosc [PLN]: " << incomes[number].getAmount() << endl;
        amount = incomes[number].getAmount();
        break;

    case EXPENSE:
        cout << "-------------------------------------------------------------" << endl;
        cout << "Numer ID: " << expenses[number].getEarningId() << endl;
        cout << "Data: ";
        dateMethods.displayDate(AuxiliaryMethods::changeDateWithoutHypenToDateWithHyphen(AuxiliaryMethods::convertIntToString(expenses[number].getDate())));
        cout << endl << "Opis: " << expenses[number].getItem() << endl;
        cout << "Wartosc [PLN]: " << expenses[number].getAmount() << endl;
        amount = expenses[number].getAmount();
        break;

    }
    return amount;
}

double BudgetManager::calculateBalanceSheet(int startDate, int endDate, const Type& type) {
    string typeDescription;
    double sumEarnings = 0;

    switch(type) {

    case INCOME:
        typeDescription = "PRZYCHODY";

        if(!incomes.empty()) {
            cout << "         <<<" << typeDescription << ">>>         " << endl;

            for (int i =0; i < (int) incomes.size(); i++) {
                if (startDate<= incomes[i].getDate()) {
                    if(endDate >= incomes[i].getDate())
                        sumEarnings += (AuxiliaryMethods::convertStringToDouble(displayEarning(i,INCOME)));
                }
            }
            cout << endl;
        } else {
            cout << endl << typeDescription << " NIE ISTNIEJA." << endl;
        }
        break;

    case EXPENSE:
        typeDescription = "WYDATKI";

        if(!expenses.empty()) {
            cout << "         <<<" << typeDescription << ">>>         " << endl;

            for (int i =0; i < (int) expenses.size(); i++) {

                if (startDate <= expenses[i].getDate()) {
                    if(endDate >= expenses[i].getDate()) {
                        sumEarnings+= (AuxiliaryMethods::convertStringToDouble(displayEarning(i, EXPENSE)));
                    }
                }
            }
            cout << endl;
        } else {
            cout << endl << typeDescription << " NIE ISTNIEJA." << endl;
        }
        break;
    }

    return sumEarnings;
}

void BudgetManager::displayCalculateBalanceSheet(int startDate, int endDate) {
    sortDateIncomes();
    sortDateExpenses();

    system("clear");//Windows system("cls")
    cout << "POKAZ SALDO" << endl;
    cout << "WYBRANY PRZEDZIAL CZASOWY: " ;
    dateMethods.displayDate(AuxiliaryMethods::changeDateWithoutHypenToDateWithHyphen(AuxiliaryMethods::convertIntToString(startDate)));
    cout << " DO " ;
    dateMethods.displayDate(AuxiliaryMethods::changeDateWithoutHypenToDateWithHyphen(AuxiliaryMethods::convertIntToString(endDate)));
    cout << endl << endl;
    double incomesSum = calculateBalanceSheet(startDate, endDate, INCOME);
    double expensesSum = calculateBalanceSheet(startDate, endDate, EXPENSE);

    cout << "-------------------------------------------------------------------" << endl;
    cout << "Suma przychodow w wybranym przedziale czasowym: " << incomesSum << " PLN." << endl;
    cout << "Suma wydatkow w wybranym przedziale czasowym: " << expensesSum << " PLN." <<endl;
    cout << "Saldo w wybranym przedziale czasowym: " << incomesSum - expensesSum << " PLN." << endl;

}
void BudgetManager::displayCurrentMonthsBalanceSheet() {
    string currentDate = dateMethods.getTimeFromSystem();
    string startDate =  (currentDate.substr(0,4) + currentDate.substr(5,2) + "01");
    string endDate = (currentDate.substr(0,4) + currentDate.substr(5,2) + AuxiliaryMethods::convertIntToString(dateMethods.checkNumberOfDaysPerMonth(dateMethods.getYearFromDate(currentDate),dateMethods.getMonthFromDate(currentDate))));
    displayCalculateBalanceSheet(AuxiliaryMethods::convertStringToInt(startDate), AuxiliaryMethods::convertStringToInt(endDate));

    system("read"); // Windows system("pause")
}

void BudgetManager::displayPreviousMonthsBalanceSheet() {
    string currentDate = dateMethods.getTimeFromSystem();
    string previousMonth = dateMethods.getPreviousMonthFromDate(currentDate);

    if (previousMonth=="12") {
        if (currentDate[3]=='0') {
            currentDate[2]--;
            currentDate[3]='9';
        } else
            currentDate[3]--;
    }
    string startDate = (currentDate.substr(0,4) + previousMonth + "01");
    string endDate = (currentDate.substr(0,4) + previousMonth + AuxiliaryMethods::convertIntToString(dateMethods.checkNumberOfDaysPerMonth(dateMethods.getYearFromDate(currentDate),AuxiliaryMethods::convertStringToInt(previousMonth))));

    displayCalculateBalanceSheet(AuxiliaryMethods::convertStringToInt(startDate), AuxiliaryMethods::convertStringToInt(endDate));

    system("read"); // Windows system("pause")
}
