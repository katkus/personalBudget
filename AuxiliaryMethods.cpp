#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine() {
    string entry = "";
    cin.sync();
    getline(cin, entry);

    return entry;
}
