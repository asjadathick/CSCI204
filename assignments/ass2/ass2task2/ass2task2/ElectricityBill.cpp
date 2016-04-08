//
//  ElectricityBill.cpp
//  ass2task2
//
//  mama158
//  Created by Asjad Athick on 5/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "ElectricityBill.h"
using namespace std;

//--------------Electricity

float ElectricityBill::rate1 = 0.245;
float ElectricityBill::rate1Threshold = 1750;
float ElectricityBill::rate2 = 0.264;
float ElectricityBill::supplyCharge = 0.699;

ElectricityBill::ElectricityBill(){
    amountDue = 0;
    totalGST = 0;
    previousReading = 0;
    currentReading = 0;
    
}

void ElectricityBill::calculateBillAmount(){
    double totalAmount = (currentReading - previousReading) * ElectricityBill::rate1;
    
    if ((currentReading - previousReading) > ElectricityBill::rate1Threshold) {
        totalAmount += ((currentReading - previousReading) - ElectricityBill::rate1Threshold) * ElectricityBill::rate2;
    }

    int billdays = (periodEndDate - periodStartDate);
    double totalSupplyCharge = billdays * ElectricityBill::supplyCharge;

    
    this->amountDue = totalAmount + totalSupplyCharge;
    this->totalGST = this->amountDue * .1;
}

ostream& operator<<(ostream& out, const ElectricityBill& bill){
    out << bill.getBillType() << ";";
    out << (*dynamic_cast<const Bill*>(&bill));
    out << ";" << bill.previousReading << ";" << bill.currentReading << ";" << fixed << setprecision(2) << bill.amountDue << ";" << setprecision(2) << bill.totalGST << endl;
    
    return out;
}

istream& operator>>(istream& in, ElectricityBill& bill){
    in >> (*dynamic_cast<Bill*>(&bill));
    string inputBuffer;
    
    cout << "Previous reading (kWh): ";
    getline(in, inputBuffer , '\n');
    bill.previousReading = (atof(inputBuffer.c_str()));
    
    cout << "Current reading (kWh): ";
    getline(in, inputBuffer , '\n');
    bill.currentReading = (atof(inputBuffer.c_str()));
    
    bill.calculateBillAmount();
    
    dynamic_cast<Bill*>(&bill)->printTotals(cout);
    
    return in;
}

void ElectricityBill::setNewRates(){
    cout << "\nSet electricity rates." << endl;
    cout << "Rate 1 ($ per kWh): ";
    cin >> ElectricityBill::rate1;
    cout << "Threshold (kWh): ";
    cin >> ElectricityBill::rate1Threshold;
    cout << "Rate 2 ($ per kWh): ";
    cin >> ElectricityBill::rate2;
    cout << "Supply charge rate ($ per day): ";
    cin >> ElectricityBill::supplyCharge;
    
    cout << "\nNew rates for electricity bills have been set\n" << endl;
}

char ElectricityBill::getBillType() const{
    return 'E';
}

void ElectricityBill::printBill(ostream& out){
    cout << "Electricity bill:" << endl;
    dynamic_cast<Bill*>(this)->printBill(out);
    
    cout << "Previous reading: " << previousReading << endl;
    cout << "Current reading: " << currentReading << endl;
    cout << "Total amount due: $" << fixed << setprecision(2) << amountDue << endl;
    cout << "Total GST: $" << fixed << setprecision(2) << totalGST << endl;
}

void ElectricityBill::loadBill(istream& input){
    //will consume 1 bill (line)
    dynamic_cast<Bill*>(this)->loadBill(input);
    
    string buffer;
    
    getline(input, buffer, ';');
    previousReading = atof(buffer.c_str());
    
    getline(input, buffer, ';');
    currentReading = atof(buffer.c_str());
    
    getline(input, buffer, ';');
    amountDue = atof(buffer.c_str());
    
    getline(input, buffer, '\n');
    totalGST = atof(buffer.c_str());
}

