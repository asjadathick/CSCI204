//
//  Bill.hpp
//  ass2task2
//
//  mama158
//  Created by Asjad Athick on 5/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef Bill_h
#define Bill_h

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

class Date{
private:
    tm time;
public:
    Date();
    void load(std::string);
    int operator-(const Date& value) const;
    friend std::ostream& operator<<(std::ostream&, const Date&);
    
};

class Bill{
protected:
    std::string billerName;
    std::string billerCode;
    std::string referenceNumber;
    std::string accountNumber;
    std::string accountName;
    std::string address;
    float amountDue;
    float totalGST;
    Date dueDate;
    Date periodStartDate;
    Date periodEndDate;
    
public:
    Bill();
    virtual ~Bill();
    friend std::ostream& operator<<(std::ostream&, const Bill&);
    friend std::istream& operator>>(std::istream&, Bill&);
    void printBill(std::ostream&);
    void loadBill(std::istream&);
    virtual void calculateBillAmount() = 0;
    virtual char getBillType() const = 0;
    virtual void printTotals(std::ostream&) const;
    
};

class BillArray{
private:
    Bill **billArray;
    unsigned int billCount;
public:
    BillArray();
    ~BillArray();
    void addBill(Bill*);
    int getBillCount();
    Bill* getBillItem(int);
    
};

#endif /* Bill_h */
