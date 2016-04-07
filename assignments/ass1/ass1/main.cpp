//
//  main.cpp
//  ass1
//
//  Created by Asjad Athick on 26/03/2016.
//  mama158
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Account.h"
#include "ATM.h"
using namespace std;

//function prototypes
Account* openAccounts(const char*, int&);
ATM* openATMs(const char*, int&);
void printMenu();
void withdraw(Account*, ATM*, int, int);
void findBalance(Account* accountArray, int accountCount);
void addNotes(ATM*, int);
int findCustomerAccount(string, string, int, Account*);
void writeToLogFile(string);
string getSystemTime();
void saveATMs(ATM*, int, const char*);
void saveAccounts(Account*, int, const char*);

//const globals
char LOG_FILENAME[] = "ATM.log";

int main(int argc, const char * argv[]) {
    if (argc < 3) {
        cout << "Destinations to account.txt and ATM.txt need to be passed into command line arguments." << endl;
        return 1;
    }
    
    //open accounts
    int accountCount = 0;
    Account* accountArray = openAccounts(argv[1],accountCount);
    
    int atmsCount = 0;
    ATM* atmArray = openATMs(argv[2], atmsCount);
    
    //prompt menu
    char buffer[10];
    int input=0;
    do{
        printMenu();
        cin.getline(buffer, 10, '\n');
        input = atoi(buffer);
        
        switch (input) {
            case 1:
                withdraw(accountArray, atmArray, accountCount, atmsCount);
                break;
            case 2:
                findBalance(accountArray, accountCount);
                break;
            case 3:
                addNotes(atmArray, atmsCount);
                break;
            case 4:
                saveAccounts(accountArray, accountCount, argv[1]);
                saveATMs(atmArray, atmsCount, argv[2]);
                break;
            default:
                cout << "Invalid option" << endl;
                
                
        }
    } while (input !=4);
    
    //prepare to quit
    
    if(accountArray != NULL)
        delete [] accountArray;
    
    if(atmArray != NULL)
        delete [] atmArray;
    
    return 0;
}

void saveATMs(ATM* atmArray, int atmCount, const char* filename){
    //open file
    ofstream atmfile;
    atmfile.open(filename, ios::out);
    
    if (!atmfile.good()) {
        cout << "ATMs could not be saved." << endl;
        return;
    }
    
    atmfile << atmCount << endl;
    
    for (int i = 0; i<atmCount; i++) {
        atmfile << atmArray[i].getATMId() << "," << atmArray[i].getBalance50() << "," << atmArray[i].getBalance20() << endl;
    }
    
    cout << "ATMs saved to " << filename << endl;
    
    atmfile.close();
}

void saveAccounts(Account* accountArray, int accountCount, const char* filename){
    ofstream accountsFile;
    accountsFile.open(filename, ios::out);
    
    if (!accountsFile.good()) {
        cout << "Accounts could not be saved." << endl;
        return;
    }
    
    accountsFile << accountCount << endl;
    
    for (int i = 0; i < accountCount; i++) {
        accountsFile << accountArray[i].getCustomerID() << "," << accountArray[i].getBSBNumber() << "," << accountArray[i].getAccountNumber() << "," << accountArray[i].getFirstName() << "," << accountArray[i].getLastName() << "," << accountArray[i].getBalance() << endl;
    }
    
    cout << "Accounts saved to " << filename << endl;
    
    accountsFile.close();
}

void withdraw(Account* accountArray, ATM* atmArray, int accountCount, int atmCount){
    //select atm
    int atmIndex = rand() % atmCount;
    if (atmArray[atmIndex].getBalance50() < 2000) {
        cout << "Please add more notes for ATM $50 note box." << endl;
        return;
    }
    if (atmArray[atmIndex].getBalance20() < 2000) {
        cout << "Please add more notes for ATM $20 note box." << endl;
        return;
    }
    
    Account withdrawAccount;
    char buffer[256];
    
    cout << "BSB: ";
    cin.getline(buffer, 256, '\n');
    withdrawAccount.setBSBNumber(buffer);
    
    cout << "Account: ";
    cin.getline(buffer, 256, '\n');
    withdrawAccount.setAccountNumber(buffer);
    
    int withdrawAmount;
    cout << "Amount: ";
    cin.getline(buffer, 256, '\n');
    withdrawAmount = atoi(buffer);
    
    if (withdrawAmount <= 0){
        cout << "Withdraw amount cannot be zero or negative" << endl;
        return;
    }
    
    //check if account can afford
    //find account
    int accountIndex = findCustomerAccount(withdrawAccount.getBSBNumber(), withdrawAccount.getAccountNumber(), accountCount, accountArray);
    
    if (accountIndex == -1) {
        cout << "Account not found on system." << endl;
        return;
    }
    
    if (accountArray[accountIndex].getBalance() < withdrawAmount){
        cout << "Your account balance is not sufficient to perform this transaction" << endl;
        return;
    }
    
    //check if amount can be withdrawn from atm
    //find notes required
    int num50 = 0;
    int num20 = 0;
    int balanceAmount = withdrawAmount;
    
    num50 = balanceAmount/50;
    balanceAmount -= (num50 * 50);
    
    num20 = balanceAmount/20;
    balanceAmount -= (num20 * 20);
    
    if (balanceAmount > 0) {
        cout << "The amount of cash cannot be withdrawn" << endl;
        return;
    }
    
    //check if atm has enough notes
    if ((atmArray[atmIndex].getBalance50() - (num50*50)) < 0 ) {
        //check if balance amount can be made with $20 notes
        int inATM = atmArray[atmIndex].getBalance50();
        int balanceRequired = (num50*50) - inATM;
        if ((balanceRequired % 20) != 0) {
            //adjust num20/num50 and try again
            inATM -= 50;
            balanceRequired += 50;
        }
        
        if ((balanceRequired %20) !=0){
            cout << "The amount of cash cannot be withdrawn" << endl;
            return;
        } else {
            num20 += (balanceRequired / 20);
            num50 = (inATM /50);
        }
        
    }
    
    if ((atmArray[atmIndex].getBalance20() - (num20*20)) < 0 ) {
        cout << "The amount of cash cannot be withdrawn" << endl;
        return;
    }
    
    //reduce customer accountbalance
    accountArray[accountIndex].setBalance(accountArray[accountIndex].getBalance() - withdrawAmount);
    accountArray[accountIndex].setWithdrawnToday(accountArray[accountIndex].getWithdrawnToday() + withdrawAmount);
    
    //reduce num of notes in ATM
    atmArray[atmIndex].withdraw50(num50);
    atmArray[atmIndex].withdraw20(num20);
    
    //write in log file
    ostringstream log;
    log << atmArray[atmIndex].getATMId() << ", " << getSystemTime() << ", withdraw, " << accountArray[accountIndex].getBSBNumber() << ", " <<accountArray[accountIndex].getAccountNumber() << ", " << withdrawAmount << "." << endl;
    writeToLogFile(log.str());
    
    //output withdraw confirmation
    cout << "You have " << num50 << "x$50 notes, " << num20 << "x$20 notes. Your balance is $" << accountArray[accountIndex].getBalance() << "." << endl;
}

void writeToLogFile(string log){
    ofstream logFile;
    logFile.open(LOG_FILENAME, ios::app);
    
    logFile << log.c_str() << endl;
    logFile.close();
}

int findCustomerAccount(string BSB, string account, int accountCount, Account* accountArray){
    int index = 0;
    for (index = 0; index < accountCount; index++) {
        if ((accountArray[index].getBSBNumber() == BSB) && accountArray[index].getAccountNumber() == account) {
            return index;
        }
    }
    return -1;
}

string getSystemTime(){
    ostringstream timeStr;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    timeStr <<  now->tm_mday <<'/' << setfill('0') << setw(2) << (now->tm_mon + 1) << '/' << (now->tm_year + 1900) << " "  << now->tm_hour << ':' << now->tm_min;
    return timeStr.str();
}

void findBalance(Account* accountArray, int accountCount){
    Account searchAccount;
    char buffer[256];
    
    cout << "BSB: ";
    cin.getline(buffer, 256, '\n');
    searchAccount.setBSBNumber(buffer);
    
    cout << "Account: ";
    cin.getline(buffer, 256, '\n');
    searchAccount.setAccountNumber(buffer);
    
    int accountIndex = findCustomerAccount(searchAccount.getBSBNumber(), searchAccount.getAccountNumber(), accountCount, accountArray);
    
    if (accountIndex == -1) {
        cout << "Account not found on file." << endl;
        return;
    }
    
    cout << "Your balance is $" << accountArray[accountIndex].getBalance() << endl;
    
}

void addNotes(ATM* ATMArray, int atmCount){
    char buffer[200];
    string atmID="";
    cout << "ATM ID: ";
    cin.getline(buffer, 200, '\n');
    atmID = buffer;
    
    cout << "Note type (1-$50, 2-$20): ";
    cin.getline(buffer, 200, '\n');
    int option = atoi(buffer);
    
    if (!((option == 1) || (option ==2))) {
        cout << "Incorrect option. Add Notes cancelled." << endl;
        return;
    }
    
    cout << "Amount: ";
    cin.getline(buffer, 200, '\n');
    int amountToAdd = atoi(buffer);
    
    if (amountToAdd <= 0) {
        cout << "Cannot add 0 or less notes into ATM" << endl;
        return;
    }
    
    int foundIndex = -1;
    
    //look for ATM
    for (int i = 0; i<atmCount; i++) {
        if (ATMArray[i].getATMId() == atmID) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex == -1) {
        cout << "Could not find ATM with ATM ID: " << atmID << endl;
        return;
    }
    
    if (option == 1) {
        if ((amountToAdd % 50) != 0) {
            cout << "The amount is not a multipe of $50, and cannot be added to the cash box." << endl;
            return;
        }
        ATMArray[foundIndex].set50(ATMArray[foundIndex].getBalance50() + amountToAdd);
    }
    
    if (option == 2) {
        if ((amountToAdd % 20) != 0) {
            cout << "The amount is not a multipe of $20, and cannot be added to the cash box." << endl;
            return;
        }
        ATMArray[foundIndex].set20(ATMArray[foundIndex].getBalance20() + amountToAdd);
    }
    
    //write log
    ostringstream log;
    log << ATMArray[foundIndex].getATMId() << ", " << getSystemTime() << ", " << (option == 1 ? "Add $50 notes, " : "Add $20 notes, ") << amountToAdd << ", " << (option == 1 ? ATMArray[foundIndex].getBalance50() : ATMArray[foundIndex].getBalance20())  << "." << endl;
    writeToLogFile(log.str());
    
    //output confirmation
    cout << "You have successfully added $" << amountToAdd << " to the " << (option == 1 ? "$50" : "$20") << " cash box, on ATM ID: " << atmID << "." << endl;
}

void printMenu(){
    cout << "1. Withdraw\n2.Find balance\n3.Add notes\n4.Quit\nPlease choose: ";
}

ATM* openATMs(const char* fileName, int &ATMCount){
    ATM *ATMArray = NULL;
    
    fstream atms;
    atms.open(fileName);
    
    if (!atms.good()) {
        cout << "Could not open ATMs file" << endl;
        return ATMArray;
    }
    
    ATMCount = 0;
    char buffer[256];
    atms.getline(buffer, 256, '\n');
    
    ATMCount = atoi(buffer);
    
    ATMArray = new(nothrow) ATM[ATMCount];
    if (ATMArray == NULL)
        return ATMArray;
    
    //load data
    
    int loadCount = 0;
    
    while (!atms.eof()) {
        ATM temp;
        
        atms.getline(buffer, 256, ',');
        temp.setATMId(buffer);
        if (!atms.eof()) {
            
            atms.getline(buffer, 256, ',');
            temp.set50(atoi(buffer));
            
            atms.getline(buffer, 256, '\n');
            temp.set20(atoi(buffer));
            
            
            ATMArray[loadCount] = temp;
            loadCount++;
        }
    }
    
    if (ATMCount == loadCount) {
        ATMCount = loadCount;
        cout << "ATMs have been loaded." << endl;
    } else {
        cout << "An error occured while loading ATMs" << endl;
    }
    
    atms.close();
    
    return ATMArray;
}

Account* openAccounts(const char* fileName, int &accountCount){
    Account *accountArray = NULL;
    
    fstream accounts;
    accounts.open(fileName);
    
    if (!accounts.good()) {
        cout << "Could not open accounts file" << endl;
        return accountArray;
    }
    
    accountCount = 0;
    char buffer[256];
    accounts.getline(buffer, 256, '\n');
    
    accountCount = atoi(buffer);
    
    accountArray = new(nothrow) Account[accountCount];
    if (accountArray == NULL)
        return accountArray;
    
    //load data
    
    int loadCount = 0;
    
    while (!accounts.eof()) {
        accounts.getline(buffer, 256, ',');
        if (!accounts.eof()) {
            accountArray[loadCount].setCustomerID(buffer);
            
            accounts.getline(buffer, 256, ',');
            accountArray[loadCount].setBSBNumber(buffer);
            
            accounts.getline(buffer, 256, ',');
            accountArray[loadCount].setAccountNumber(buffer);
            
            accounts.getline(buffer, 256, ',');
            accountArray[loadCount].setFirstName(buffer);
            
            accounts.getline(buffer, 256, ',');
            accountArray[loadCount].setLastName(buffer);
            
            accounts.getline(buffer, 256, '\n');
            accountArray[loadCount].setBalance(atof(buffer));
            
            loadCount++;
        }
    }
    
    if (accountCount == loadCount) {
        accountCount = loadCount;
        cout << "Accounts have been loaded" << endl;
    } else {
        cout << "An error occured while loading accounts." << endl;
    }
    
    accounts.close();
    
    return accountArray;
};
