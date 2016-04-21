//
//  Bank.cpp
//  lab5
//
//  Created by Asjad Athick on 10/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "Bank.h"
using namespace std;

//------Account

Account::Account(){
    balance = 0;
}

ostream& operator<<(ostream& out, const Account& instance){
    out << "BSB#: " << instance.bsbNumber << ", ";
    out << "Account#: " << instance.accountNumber << ", ";
    out << instance.name << ", ";
    return out;
}


//------Saving

Saving::Saving(string prBSB, string prAccount, string prName, string prAddress, string prPhone, double prBalance, string prCard){
    this->bsbNumber = prBSB;
    this->accountNumber = prAccount;
    this->name = prName;
    this->address = prAddress;
    this->phoneNumber = prPhone;
    this->balance = prBalance;
    this->cardNumber = prCard;
    this->interestAmount = 0;
}

void Saving::interest(){
    float interestPerDay = 0.3 / (360*100);
    interestAmount = balance * interestPerDay * 30;
    interestAmount =  ceil(interestAmount * 100) / 100;
    balance += interestAmount;
}

ostream& operator<<(ostream& out, const Saving& instance){
    out << *dynamic_cast<const Account*>(&instance);
    out << "Saving, ";
    out << "Card#: " << instance.cardNumber << ", ";
    out << "Balance: $" << instance.balance << " CR, ";
    out << "Interest paid: $" << instance.interestAmount;
    return out;
}

//------Credit

Credit::Credit(string prBSB, string prAccount, string prName, string prAddress, string prPhone, double prBalance, string prCard, double prLimit, int prRepaymentDue){
    this->bsbNumber = prBSB;
    this->accountNumber = prAccount;
    this->name = prName;
    this->address = prAddress;
    this->phoneNumber = prPhone;
    this->balance = prBalance;
    this->cardNumber = prCard;
    this->limitation = prLimit;
    this->repaymentDue = prRepaymentDue;
    this->interestAmount = 0;
}

void Credit::interest(){
    float interestRate;
    if (repaymentDue <= 15) {
        interestRate = .125;
    } else {
        interestRate = .18;
    }
    
    float interestRatePerDay = interestRate / 360;
    interestAmount = balance * interestRatePerDay * repaymentDue;
    interestAmount =  ceil(interestAmount * 100) / 100;
    balance += interestAmount;

}

ostream& operator<<(ostream& out, const Credit& instance){
    out << *dynamic_cast<const Account*>(&instance);
    out << "Credit, ";
    out << "Card#: " << instance.cardNumber << ", ";
    out << "Balance: $" << instance.balance << " DR, ";
    out << "Interest charges: $" << instance.interestAmount;
    return out;
}

