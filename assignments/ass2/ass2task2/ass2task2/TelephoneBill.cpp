//
//  TelephoneBill.cpp
//  ass2task2
//
//  mama158
//  Created by Asjad Athick on 6/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "TelephoneBill.h"
using namespace std;

//-------Telephone Bill

float TelephoneBill::localCallRate = 0.3;
float TelephoneBill::lineRental = 29.9;
float TelephoneBill::internetConnection = 35;

TelephoneBill::TelephoneBill(){
    numberOfLocalCalls = 0;
    internationalCallAmount = 0;
}

void TelephoneBill::calculateBillAmount(){
    double totalLocalCall = numberOfLocalCalls * localCallRate;
    this->amountDue = totalLocalCall + internationalCallAmount + lineRental + internetConnection;
    this->totalGST = this->amountDue * .1;
}

char TelephoneBill::getBillType() const{
    return 'T';
}

ostream& operator<<(ostream& out, const TelephoneBill& bill){
    out << bill.getBillType() << ";";
    out << (*dynamic_cast<const Bill*>(&bill));
    out << ";" << bill.numberOfLocalCalls << ";" << bill.internationalCallAmount << ";" << fixed << setprecision(2) << bill.amountDue << ";" << setprecision(2) << bill.totalGST << endl;
    
    return out;
}

istream& operator>>(istream& in, TelephoneBill& bill){
    in >> (*dynamic_cast<Bill*>(&bill));
    string inputBuffer;
    
    cout << "Number of local calls: ";
    getline(in, inputBuffer , '\n');
    bill.numberOfLocalCalls = (atof(inputBuffer.c_str()));
    
    cout << "International calls: ";
    getline(in, inputBuffer , '\n');
    bill.internationalCallAmount = (atof(inputBuffer.c_str()));
    
    bill.calculateBillAmount();
    
    dynamic_cast<Bill*>(&bill)->printTotals(cout);
    
    return in;
}

void TelephoneBill::printBill(ostream& out){
    cout << "Telephone bill:" << endl;
    dynamic_cast<Bill*>(this)->printBill(out);
    
    cout << "Number of local calls: " << numberOfLocalCalls << endl;
    cout << "International calls: $" << internationalCallAmount << endl;
    cout << "Total amount due: $" << fixed << setprecision(2) << amountDue << endl;
    cout << "Total GST: $" << fixed << setprecision(2) << totalGST << endl;
}

void TelephoneBill::loadBill(istream& input){
    //will consume 1 bill (line)
    dynamic_cast<Bill*>(this)->loadBill(input);
    
    string buffer;
    
    getline(input, buffer, ';');
    numberOfLocalCalls = atof(buffer.c_str());
    
    getline(input, buffer, ';');
    internationalCallAmount = atof(buffer.c_str());
    
    getline(input, buffer, ';');
    amountDue = atof(buffer.c_str());
    
    getline(input, buffer, '\n');
    totalGST = atof(buffer.c_str());
}
