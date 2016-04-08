//
//  Bill.cpp
//  ass2task2
//
//  mama158
//  Created by Asjad Athick on 5/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "Bill.h"
using namespace std;
//---------Date

Date::Date(){
    time_t rtime;
    std::time(&rtime);
    this->time = *localtime(&rtime);
}

void Date::load(string timestr){
    int day = 1, month = 1, year = 0;
    char *rawString = new char[timestr.length()+1];
    strcpy(rawString, timestr.c_str());
    
    char *strptr;
    
    strptr = strtok(rawString, " /");
    if (strptr != NULL)
        day = atoi(strptr);
    
    strptr = strtok(NULL, " /");
    if (strptr != NULL)
        month = atoi(strptr);
    
    strptr = strtok(NULL, " /");
    if (strptr != NULL)
        year = atoi(strptr);
    
    this->time.tm_year = year - 1990;
    this->time.tm_mon = month - 1;
    this->time.tm_mday = day;
    mktime(&(this->time));
    
    delete [] rawString;
}

int Date::operator-(const Date& value) const{
    tm thistime = this->time;
    tm otime = value.time;
    time_t thisrtime = mktime(&thistime);
    time_t ortime = mktime(&otime);
    double timeDiffSec = difftime(thisrtime, ortime);
    
    int days = timeDiffSec / (60 * 60 * 24);
    
    return days+1;
}

ostream& operator<<(ostream& out, const Date &value){
    out << value.time.tm_mday << "/" << (value.time.tm_mon + 1) << "/" << (value.time.tm_year + 1990);
    return out;
}

//---------Bill

ostream& operator<<(ostream& out, const Bill& bill){
    out << bill.billerName << ";" << bill.billerCode << ";" << bill.referenceNumber << ";" << bill.accountNumber << ";" << bill.accountName << ";" << bill.address << ";" << bill.periodStartDate << ";" << bill.periodEndDate << ";" << bill.dueDate;
    
    return out;
}

istream& operator>>(istream& in, Bill& bill){
    string inputBuffer;
    
    cout << "Biller name: ";
    getline(in, inputBuffer , '\n');
    bill.billerName = inputBuffer;
    
    
    cout << "Biller code: ";
    getline(in, inputBuffer , '\n');
    bill.billerCode = inputBuffer;
    
    cout << "Reference: ";
    getline(in, inputBuffer , '\n');
    bill.referenceNumber = inputBuffer;
    
    cout << "Account number: ";
    getline(in, inputBuffer , '\n');
    bill.accountNumber = inputBuffer;
    
    cout << "Account name: ";
    getline(in, inputBuffer , '\n');
    bill.accountName = inputBuffer;
    
    cout << "Address: ";
    getline(in, inputBuffer , '\n');
    bill.address = inputBuffer;
    
    cout << "Start date: ";
    getline(in, inputBuffer , '\n');
    bill.periodStartDate.load(inputBuffer);
    
    cout << "End date: ";
    getline(in, inputBuffer , '\n');
    bill.periodEndDate.load(inputBuffer);
    
    cout << "Due date: ";
    getline(in, inputBuffer , '\n');
    bill.dueDate.load(inputBuffer);
    
    return in;
}


Bill::Bill(){
    amountDue = 0;
    totalGST = 0;
}

Bill::~Bill(){
    
}

void Bill::printTotals(ostream& out) const{
    out << "\nTotal amount due: $" << fixed << setprecision(2) << this->amountDue << "\nTotal GST: $" << fixed << setprecision(2) << this->totalGST << "\n" << endl;
}

void Bill::printBill(ostream& out){
    out << "Biller name: " << this->billerName << endl;
    out << "Biller code: " << this->billerCode << endl;
    out << "Reference number: " << this->referenceNumber << endl;
    out << "Account number: " << this->accountNumber << endl;
    out << "Account name: " << this->accountName << endl;
    out << "Address: " << this->address << endl;
    out << "Start date: " << this->periodStartDate << endl;
    out << "End date: " << this->periodEndDate << endl;
    out << "Due date: " << this->dueDate << endl;
    
}

void Bill::loadBill(istream& input){
    //consume semicolon after type
    string buffer;
    getline(input, buffer, ';');
    
    getline(input, billerName, ';');
    getline(input, billerCode, ';');
    getline(input, referenceNumber, ';');
    getline(input, accountNumber, ';');
    getline(input, accountName, ';');
    getline(input, address, ';');
    
    getline(input, buffer, ';');
    periodStartDate.load(buffer);
    
    getline(input, buffer, ';');
    periodEndDate.load(buffer);
    
    getline(input, buffer, ';');
    dueDate.load(buffer);
    
}

//-------BillArray
BillArray::BillArray(){
    billArray = NULL;
    billCount = 0;
}

BillArray::~BillArray(){
    for (int i = 0; i<billCount; i++) {
        delete billArray[i];
    }
    
    if (billArray != NULL)
        delete [] billArray;
    
    billCount = 0;
}

void BillArray::addBill(Bill *newBill){
    Bill **oldBillArray = billArray;
    billArray = new Bill*[billCount+1];
    
    //copy old memory to new list
    memcpy(billArray, oldBillArray, billCount * sizeof(Bill*));
    
    //delete old bill array
    if (oldBillArray != NULL) delete [] oldBillArray;
    billArray[billCount] = newBill;
    billCount++;
}

int BillArray::getBillCount(){
    return billCount;
}

Bill* BillArray::getBillItem(int index){
    return billArray[index];
}
