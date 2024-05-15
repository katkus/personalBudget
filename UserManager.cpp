#include "UserManager.h"

void UserManager::registerUser() {
    User user = getNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("read"); // Windows system("pause");
}

User UserManager::getNewUserData() {
    User user;

    user.setId(getNewUserId());
    string firstName;
    cout << "Podaj imie: ";
    firstName = AuxiliaryMethods::loadLine();
    user.setFirstName(firstName);

    string lastName;
    cout << "Podaj nazwisko: ";
    lastName = AuxiliaryMethods::loadLine();
    user.setLastName(lastName);

    string login;
    do {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::loadLine();
        user.setLogin(login);
    } while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    password = AuxiliaryMethods::loadLine();

    user.setPassword(password);

    return user;
}
int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId()+ 1;
}
bool UserManager::loginExists(string login) {
    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
void UserManager::showAllUsers() {

    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getFirstName() << endl;
        cout << users[i].getLastName() << endl;
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}
void UserManager::loginUser() {
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector<User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("read"); // Windows system("pause");

                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("read"); // Windows system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;

    system("read"); // Windows system("pause");
    return ;
}
void UserManager::logoutUser() {
    loggedInUserId = 0;
}
