//
//  Bank.hpp
//  lab5
//
//  Created by Asjad Athick on 10/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef Bank_h
#define Bank_h

#include <iostream>
#include <cmath>

class Account{
protected:
    std::string bsbNumber;
    std::string accountNumber;
    std::string name;
    std::string address;
    std::string phoneNumber;
    double balance;
    std::string cardNumber;
public:
    Account();
    friend std::ostream& operator<<(std::ostream&, const Account&);
    
};

class Saving: public Account{
private:
    double interestAmount;
public:
    Saving(std::string,std::string,std::string,std::string,std::string, double, std::string);
    void interest();
    friend std::ostream& operator<<(std::ostream&, const Saving&);
};

class Credit: public Account{
private:
    double interestAmount;
    double limitation;
    int repaymentDue;
public:
    Credit(std::string,std::string,std::string,std::string,std::string,double,std::string,double,int);
    void interest();
    friend std::ostream& operator<<(std::ostream&, const Credit&);
};



#endif /* Bank_h */
