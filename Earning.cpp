#include "Earning.h"


void Earning::setEarningId (int newEarningId) {
    if (newEarningId >= 0)
        earningId = newEarningId;
}
void Earning::setUserId (int newUserId) {
    if (newUserId >= 0)
        userId = newUserId;
}
void Earning::setDate (int newDate) {
    date = newDate;
}
void Earning::setItem (string newItem) {
    item = newItem;
}
void Earning::setAmount (string newAmount) {
    amount = newAmount;
}
int Earning::getEarningId () {
    return earningId;
}
int Earning::getUserId () {
    return userId;
}
int Earning::getDate() {
    return date;
}
string Earning::getItem () {
    return item;
}
string Earning::getAmount () {
    return amount;
}
