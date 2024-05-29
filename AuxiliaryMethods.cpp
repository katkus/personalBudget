#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine() {
    string entry = "";
    cin.sync();
    getline(cin, entry);

    return entry;
}

char AuxiliaryMethods::loadCharacter() {

    string entrance = "";
    char character  = {0};

    while (true) {
        getline(cin, entrance);

        if (entrance.length() == 1) {
            character = entrance[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }

    return character;

}

int AuxiliaryMethods::convertStringToInt(string number) {

    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;

}
string AuxiliaryMethods::changeDateWithHypenToDateWithoutHyphen(string date) {

    string dateWithoutHyphen = (date.substr(0,4)) + (date.substr(5,2)) + (date.substr(8,2));

    return dateWithoutHyphen;
}

string AuxiliaryMethods::replaceCommaToDot (string amount) {

    int sizeOfAmount = amount.size();

    for (int i = 0; i < sizeOfAmount; i++) {

        if ((amount[i] == ',') ||(amount[i]=='.')) {
            amount[i] = '.';
            if (sizeOfAmount > i+3)
                amount.erase(i+3, sizeOfAmount-i-3);
            return amount;
        }
    }

    return amount;

}
string AuxiliaryMethods::convertIntToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}
string AuxiliaryMethods::changeDateWithoutHypenToDateWithHyphen(string date) {

    string dateWithHyphen = (date.substr(0,4)) + (date.substr(4,2)) + (date.substr(6,2));
    dateWithHyphen.insert(4, "-");
    dateWithHyphen.insert(7, "-");

    return dateWithHyphen;
}

double AuxiliaryMethods::convertStringToDouble(string amount) {

    double amountDouble = atof(amount.c_str());

    return amountDouble;
}
