//
//  GasBill.cpp
//  ass2task2
//
//  Created by Asjad Athick on 6/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "GasBill.h"
using namespace std;

//------Gas Bill
float GasBill::heatingValue = 38.82;
float GasBill::pressureFactor = 0.9942;
float GasBill::rate = 0.0297;
float GasBill::supplyCharge = 0.443;

GasBill::GasBill(){
    previousReading = 0;
    currentReading = 0;
    amountDue = 0;
    totalGST = 0;
}

void GasBill::calculateBillAmount(){
    double totalMJ = (currentReading - previousReading) * heatingValue * pressureFactor;
    double totalAmountGas = totalMJ * rate;
    double amountSupplyCharge = (periodEndDate - periodStartDate) * supplyCharge;
    double totalAmountDue = totalAmountGas + amountSupplyCharge;
    this->amountDue = totalAmountDue;
    this->totalGST = this->amountDue * .1;
}

ostream& operator<<(ostream& out, const GasBill& bill){
    out << bill.getBillType() << ";";
    out << (*dynamic_cast<const Bill*>(&bill));
    out << ";" << bill.previousReading << ";" << bill.currentReading << ";" << bill.amountDue << ";" << bill.totalGST << endl;
    
    return out;
}

istream& operator>>(istream& in, GasBill& bill){
    in >> (*dynamic_cast<Bill*>(&bill));
    string inputBuffer;
    
    cout << "Previous reading (Cubic meters): ";
    getline(in, inputBuffer , '\n');
    bill.previousReading = (atof(inputBuffer.c_str()));
    
    cout << "Current reading (Cubic meters): ";
    getline(in, inputBuffer , '\n');
    bill.currentReading = (atof(inputBuffer.c_str()));
    
    bill.calculateBillAmount();
    
    dynamic_cast<Bill*>(&bill)->printTotals(cout);
    
    return in;
}

char GasBill::getBillType() const{
    return 'G';
}

void GasBill::setNewRates(){
    cout << "Set gas rates." << endl;
    
    cout << "Rate ($ per MJ): ";
    cin >> GasBill::rate;
    
    cout << "Heating value: ";
    cin >> GasBill::heatingValue;
    
    cout << "Pressure factor: ";
    cin >> GasBill::pressureFactor;
    
    cout << "Supply charge rate ($ per day): ";
    cin >> GasBill::supplyCharge;
    
    cout << "\nNew rates for gas bills have been set." << endl;
}
