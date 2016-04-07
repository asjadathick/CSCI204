//
//  BigInteger.hpp
//  lab4
//
//  mama158
//  Created by Asjad Athick on 2/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef BigInteger_h
#define BigInteger_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <istream>

class BigInteger{
private:
    short *value;
    long size;
public:
    BigInteger();
    BigInteger(const char*);
    BigInteger(const BigInteger&);
    ~BigInteger();
    friend std::ostream& operator<<(std::ostream&, const BigInteger&);
    friend std::istream& operator>>(std::istream&, BigInteger&);
    BigInteger& operator=(const BigInteger&);
    BigInteger operator+(const BigInteger&) const;
    BigInteger operator*(const BigInteger&);
    bool operator==(const BigInteger&);
    std::string padWithZero(long) const;
    void clearStringStream(std::ostringstream&);
    
    
};

#endif /* BigInteger_h */
