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
#include <fstream>
#include <ostream>

using namespace std;

//prototypes
void printMenu();
void inputElectricityBill(BillArray &array, bool input=true, std::istream& inputStream = std::cin);
void inputGasBill(BillArray &array, bool input=true, std::istream& inputStream = std::cin);
void inputTelephoneBill(BillArray &array, bool input=true, std::istream& inputStream = std::cin);
void setElectricityRate();
void setGasRate();
void saveBillDataInTextFile(BillArray&);
void loadBillDataFromTextFile(BillArray &);

const int MAX_FILENAME_SIZE = 256;


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
                
            case 6:
                saveBillDataInTextFile(array);
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

void inputElectricityBill(BillArray &array, bool input, std::istream& inputStream){
    ElectricityBill *bill = new ElectricityBill;
    if (input){
        cout << "Input electricity bill data." << endl;
        cin >> *bill;
    }
    else
        bill->loadBill(inputStream);
        
    array.addBill(bill);
}

void inputGasBill(BillArray &array, bool input, std::istream& inputStream){
    GasBill *bill = new GasBill;
    if (input){
        cout << "Input gas bill data." << endl;
        cin >> *bill;
    }
    else
        bill->loadBill(inputStream);
    
    array.addBill(bill);
}

void inputTelephoneBill(BillArray &array, bool input, std::istream& inputStream){
    TelephoneBill *bill = new TelephoneBill;
    if (input){
        cout << "Input telephone bill data." << endl;
        cin >> *bill;
    }
    else
        bill->loadBill(inputStream);
    
    array.addBill(bill);

}

void setElectricityRate(){
    ElectricityBill::setNewRates();
}

void setGasRate(){
    GasBill::setNewRates();
}

void saveBillDataInTextFile(BillArray &array){
    char filename[MAX_FILENAME_SIZE];
    cout << "\nText file name: ";
    cin.getline(filename, 256, '\n');
    
    ofstream outputFile;
    outputFile.open(filename);
    
    if (!outputFile.good()) {
        cout << "Failed to open " << filename << " for output." << endl;
        return;
    }
    
    int i;
    
    for (i = 0; i < array.getBillCount(); i++) {
        //determine type
        Bill *billptr = array.getBillItem(i);
        switch (billptr->getBillType()) {
            case 'E':
                outputFile << *dynamic_cast<ElectricityBill*>(array.getBillItem(i)) << endl;
                break;
            case 'G':
                outputFile << *dynamic_cast<GasBill*>(array.getBillItem(i)) << endl;
                break;
            case 'T':
                outputFile << *dynamic_cast<TelephoneBill*>(array.getBillItem(i)) << endl;
                break;
            default:
                outputFile << "Invalid bill type detected for bill: " << i << endl;
                break;
        }
        
    }
    
    cout << i << " bill(s) have been saved." << endl;
}

void loadBillDataFromTextFile(BillArray &array){
    char filename[MAX_FILENAME_SIZE];
    
    cout << "\nText file name: ";
    cin.getline(filename, MAX_FILENAME_SIZE, '\n');
    
    ifstream inputFile;
    inputFile.open(filename);
    
    if (!inputFile.good()) {
        cout << "File could not be opened. Load failed." << endl;
        return;
    }
    
    int loadCount = 0;
    
    while (!inputFile.eof()) {
        //load records
        char type = inputFile.get();
        
        switch (type) {
            case 'E':
                inputElectricityBill(array, false, inputFile);
                break;
            case 'G':
                inputGasBill(array, false, inputFile);
                break;
            case 'T':
                inputTelephoneBill(array, false, inputFile);
                break;
            default:
                cout << "Invalid bill type encountered during bill load " << loadCount << endl;
                loadCount--;
                break;
        }
        loadCount++;
    }
    
}
