#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{

   PersonalBudget personalBudget ("users.xml", "incomes.xml", "expenses.xml");

  char choice;

    while (true)
    {
        if (!personalBudget.isUserLoggedIn())
        {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("read"); // Windows system("pause")
                break;
            }
        }
        else
       {
            choice = personalBudget.selectOptionFromBudgetMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayCurrentMonthsBalanceSheet();
                break;
            case '4':
                personalBudget.displayPreviousMonthsBalanceSheet();
                break;
            case '5':
                personalBudget.displayBalanceSheetFromSelectedTimePeriod();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logoutUser();
                break;
            }
        }
    }
        return 0;

}
