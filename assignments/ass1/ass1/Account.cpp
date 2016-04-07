//
//  Account.cpp
//  ass1
//
//  Created by Asjad Athick on 26/03/2016.
//  mama158
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "Account.h"
using namespace std;


Account::Account(){
    this->customerID = "";
    this->BSBNumber = "";
    this->accountNumber = "";
    this->firstName = "";
    this->lastName = "";
    this->balance = 0;
    this->withdrawnToday = 0;
}

string Account::getCustomerID(){
    return this->customerID;
}

void Account::setCustomerID(string val){
    this->customerID = val;
}

string Account::getBSBNumber(){
    return this->BSBNumber;
}

void Account::setBSBNumber(string val){
    this->BSBNumber = val;
}

string Account::getAccountNumber(){
    return this->accountNumber;
}

void Account::setAccountNumber(string val){
    this->accountNumber = val;
}

string Account::getFirstName(){
    return this->firstName;
}

void Account::setFirstName(string val){
    this->firstName = val;
}

string Account::getLastName(){
    return this->lastName;
}

void Account::setLastName(string val){
    this->lastName = val;
}

double Account::getBalance(){
    return this->balance;
}

void Account::setBalance(double val){
    this->balance = val;
}

double Account::getWithdrawnToday(){
    return this->withdrawnToday;
}

void Account::setWithdrawnToday(double val){
    this->withdrawnToday = val;
}
