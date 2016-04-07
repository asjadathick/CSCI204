//
//  ATM.cpp
//  ass1
//
//  Created by Asjad Athick on 26/03/2016.
//  mama158
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "ATM.h"
using namespace std;

ATM::ATM(){
    ATMid = "";
    totalCash50 = 0;
    totalCash20 = 0;
}

ATM& ATM::operator=(const ATM& other){
    this->ATMid = other.ATMid;
    this->totalCash50 = other.totalCash50;
    this->totalCash20 = other.totalCash20;
    return *this;
}

void ATM::setATMId(string val){
    this->ATMid = val;
}

string ATM::getATMId(){
    return this->ATMid;
}

void ATM::set50(int value){
    this->totalCash50 = value;
}

void ATM::set20(int value){
    this->totalCash20 = value;
}

int ATM::getBalance50(){
    return this->totalCash50;
}

int ATM::getBalance20(){
    return this->totalCash20;
}

bool ATM::withdraw50(int num){
    if ((totalCash50 - (50*num)) <0) {
        return false;
    } else {
        totalCash50 -= (50 * num);
        return true;
    }
}

bool ATM::withdraw20(int num){
    if ((totalCash20 - (20*num)) <0) {
        return false;
    } else {
        totalCash20 -= (20 * num);
        return true;
    }
}
