//
//  main.cpp
//  ass2task2
//
//  Created by Asjad Athick on 5/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "Bill.h"
#include "ElectricityBill.h"
#include "GasBill.h"
#include "TelephoneBill.h"

using namespace std;

//prototypes
void printMenu();
void inputElectricityBill(BillArray &);
void inputGasBill(BillArray &);
void inputTelephoneBill(BillArray &);
void setElectricityRate();
void setGasRate();


int main(int argc, const char * argv[]) {
    
    bool exit = false;
    BillArray array;
    
    while (!exit) {
        int input = 0;
        printMenu();
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (input) {
            case 0:
                exit = true;
                break;
                
            case 1:
                inputElectricityBill(array);
                break;
                
            case 2:
                inputGasBill(array);
                break;
                
            case 3:
                inputTelephoneBill(array);
                break;
                
            case 4:
                setElectricityRate();
                break;
                
            case 5:
                setGasRate();
                break;
                
            default:
                cout << "Invalid choice." << endl;
                break;
        }
        
    }
    
    cout << "The program will exit." << endl;
    
}

void printMenu(){
    cout << "1. Input electricity bill data;\n";
    cout << "2. Input gas bill data;\n";
    cout << "3. Input telephone bill data;\n";
    cout << "4. Set electricity rates;\n";
    cout << "5. Set gas rate;\n";
    cout << "6. Save bill data in a text file;\n";
    cout << "7. Load bill data from a text file;\n";
    cout << "0. Quit.";
    cout << "Your choice: " << endl;
}

void inputElectricityBill(BillArray &array){
    cout << "Input electricity bill data." << endl;
    ElectricityBill *bill = new ElectricityBill;
    cin >> *bill;
    array.addBill(bill);
}

void inputGasBill(BillArray &array){
    cout << "Input gas bill data." << endl;
    GasBill *bill = new GasBill;
    cin >> *bill;
    array.addBill(bill);
}

void inputTelephoneBill(BillArray &array){
    cout << "Input telephone bill data." << endl;
    TelephoneBill *bill = new TelephoneBill;
    cin >> *bill;
    array.addBill(bill);
}

void setElectricityRate(){
    ElectricityBill::setNewRates();
}

void setGasRate(){
    GasBill::setNewRates();
}
