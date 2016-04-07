//
//  BigInteger.hpp
//  lab3
//
//  Created by Asjad Athick on 21/03/2016.
//  Student: mama158
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef BigInteger_h
#define BigInteger_h

#include <iostream>

class BigInteger{
private:
    short *value;
    long size;
public:
    BigInteger();
    ~BigInteger();
    BigInteger(long long int);
    BigInteger(char*);
    BigInteger(const BigInteger&);
    BigInteger add(BigInteger);
    void print(std::ostream&);
    std::string padWithZero(long);
    
};

#endif /* BigInteger_h */
