#include "FileWithEarning.h"

bool FileWithEarning::addEarningToFile(Earning &earning, const Type &type) {
    int earningid = earning.getEarningId();
    string earningID = AuxiliaryMethods::convertIntToString(earningid);

    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");

        switch(type) {
        case INCOME:
            xml.AddElem("Incomes");
            break;
        case EXPENSE:
            xml.AddElem("Expenses");
            break;
        }
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Earning");
    xml.IntoElem();
    xml.AddElem("EarningId", earning.getEarningId());
    xml.AddElem("UserId", earning.getUserId());
    xml.AddElem("Date", AuxiliaryMethods::changeDateWithoutHypenToDateWithHyphen(AuxiliaryMethods::convertIntToString(earning.getDate())));
    xml.AddElem("Item", earning.getItem());
    xml.AddElem("Amount", earning.getAmount());

    xml.OutOfElem();

    if (xml.Save(getFileName())) {
        lastId++;
        return true;
    } else {
        return false;
    }
}

vector <Earning> FileWithEarning::loadEarningOfLoggedInUserFromFile(int loggedInUserId) {
    Earning earning;
    vector <Earning> earnings;

    bool fileExists = xml.Load(getFileName());

    if (fileExists) {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Earning")) {
            xml.FindChildElem("EarningId");
            int earningId = atoi( MCD_2PCSZ(xml.GetChildData()));
            xml.FindChildElem("UserId");
            int userId = atoi( MCD_2PCSZ(xml.GetChildData()));
            if (userId == loggedInUserId) {
                earning.setEarningId(earningId);
                earning.setUserId(userId);
                xml.FindChildElem("Date");
                MCD_STR date = xml.GetChildData();
                earning.setDate(AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::changeDateWithHypenToDateWithoutHyphen(date)));
                xml.FindChildElem("Item");
                MCD_STR item = xml.GetChildData();
                earning.setItem(item);
                xml.FindChildElem("Amount");
                MCD_STR amount = xml.GetChildData();
                earning.setAmount(amount);

                earnings.push_back(earning);
            }
            lastId++;
        }
        xml.OutOfElem();

    } else
        cout << "Nie mozna otworzyc pliku." << endl;
    return earnings;
}
