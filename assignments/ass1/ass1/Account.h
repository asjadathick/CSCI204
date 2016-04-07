//
//  Account.hpp
//  ass1
//
//  Created by Asjad Athick on 26/03/2016.
//  mama158
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef Account_h
#define Account_h

#include <iostream>

class Account{
private:
    std::string customerID;
    std::string BSBNumber;
    std::string accountNumber;
    std::string firstName;
    std::string lastName;
    double balance;
    double withdrawnToday;
    
public:
    Account();
    
    std::string getCustomerID();
    void setCustomerID(std::string);
    
    std::string getBSBNumber();
    void setBSBNumber(std::string);
    
    std::string getAccountNumber();
    void setAccountNumber(std::string);
    
    std::string getFirstName();
    void setFirstName(std::string);
    
    std::string getLastName();
    void setLastName(std::string);
    
    double getBalance();
    void setBalance(double);
    
    double getWithdrawnToday();
    void setWithdrawnToday(double);
};

#endif /* Account_h */
