//
//  ATM.hpp
//  ass1
//
//  Created by Asjad Athick on 26/03/2016.
//  mama158
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef ATM_h
#define ATM_h

#include <iostream>

class ATM{
private:
    std::string ATMid;
    int totalCash50;
    int totalCash20;
    
public:
    ATM();
    ATM& operator=(const ATM& other);
    
    void setATMId(std::string);
    std::string getATMId();
    
    void set50(int);
    void set20(int);
    
    int getBalance50();
    int getBalance20();
    
    bool withdraw50(int);
    bool withdraw20(int);
};

#endif /* ATM_h */
