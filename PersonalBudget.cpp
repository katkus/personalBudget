#include "PersonalBudget.h"

void PersonalBudget::registerUser() {
    userManager.registerUser();
}
void PersonalBudget::showAllUsers() {
    userManager.showAllUsers();
}
void PersonalBudget::loginUser() {
    userManager.loginUser();
}
void PersonalBudget::logoutUser() {
    userManager.logoutUser();
}
