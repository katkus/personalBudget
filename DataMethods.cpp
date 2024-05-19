#include "DateMethods.h"

string DateMethods::getTimeFromSystem() {
    char bufor [ 64 ];
    time_t timeTakenFromComputer;
    time( & timeTakenFromComputer );
    tm timeTakenFromComputerTM = * localtime( & timeTakenFromComputer );
    strftime( bufor, sizeof( bufor ), "%Y-%m-%d", & timeTakenFromComputerTM );
    string date = bufor;
    return date;
}
bool DateMethods::checkFormatDateIsCorrect(string date) {

    if ((date[4]=='-') && (date[7]=='-') && date.size()==10) {
        int year, month, day, lastDayOfMonth, currentYear, currentMonth;
        string currentDate;

        year = getYearFromDate(date);
        day = getDayFromDate(date);
        month = getMonthFromDate(date);

        currentDate = getTimeFromSystem();
        currentYear = getYearFromDate(currentDate);
        currentMonth = getMonthFromDate(currentDate);
        lastDayOfMonth = checkNumberOfDaysPerMonth(year, month);

        if ((year >= 2000) && (year <= currentYear)) {
            if ((month >= 1) && (month <= 12)) {
                if ((day >= 1) && (day <= lastDayOfMonth)) {
                    if (year == currentYear) {
                        if (month > currentMonth)
                            return false;
                    }
                    return true;
                }
            }

        }
    }
    return false;
}
