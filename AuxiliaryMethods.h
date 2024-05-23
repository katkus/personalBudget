#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

class AuxiliaryMethods {
public:
    static string loadLine();
    static char loadCharacter();
    static int convertStringToInt(string number);
    static string changeDateWithHypenToDateWithoutHyphen(string date);
    static string replaceCommaToDot (string amount);
    static string convertIntToString(int number);
    static string changeDateWithoutHypenToDateWithHyphen(string date);
    static double convertStringToDouble(string amount);

};
#endif // AUXILIARYMETHODS_H
