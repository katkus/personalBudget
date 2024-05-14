#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User &user) {
    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("LastName",user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.OutOfElem();

    if (xml.Save(getFileName())) {
        cout << "Dane zostaly zapisane." << endl;
    } else {
        cout << "Nie udalo sie zapisac danych." << endl;
    }
}
vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;

    bool fileExists = xml.Load(getFileName());

    if (fileExists) {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.FindChildElem("UserId");
            int userId = atoi( MCD_2PCSZ(xml.GetChildData()));
            user.setId(userId);
            xml.FindChildElem("FirstName");
            MCD_STR firstName = xml.GetChildData();
            user.setFirstName(firstName);
            xml.FindChildElem("LastName");
            MCD_STR lastName = xml.GetChildData();
            user.setLastName(lastName);
            xml.FindChildElem("Login");
            MCD_STR login = xml.GetChildData();
            user.setLogin(login);
            xml.FindChildElem("Password");
            MCD_STR password = xml.GetChildData();
            user.setPassword(password);

            users.push_back(user);
        }
        xml.OutOfElem();

    } else
        cout << "Nie mozna otworzyc pliku." << endl;

    return users;
}

