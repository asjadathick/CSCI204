//
//  BigInteger.cpp
//  lab4
//
//  mama158
//  Created by Asjad Athick on 2/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//


#include "BigInteger.h"
using namespace std;

BigInteger::BigInteger(){
    size = 1;
    value = new short [size];
    value[0]='0';
}

BigInteger::BigInteger(const char* array){
    //null terminator expected at end of char array
    this->size=strlen(array);
    this->value = new short[this->size+1];
    
    for (int i = 0; i<this->size; i++) {
        this->value[i] = array[i];
    }
}

BigInteger::BigInteger(const BigInteger& cpy){
    this->size = cpy.size;
    
    this->value = new short int [this->size];
    memset(this->value, 0, this->size);
    
    for (int i = 0; i<this->size; i++) {
        this->value[i] = cpy.value[i];
    }
}

BigInteger::~BigInteger(){
    if (this->value != NULL)
        delete [] value;
}

ostream& operator<<(ostream& out, const BigInteger &value){
    out.flush();
    for (int i = 0; i<value.size; i++) {
        out << (char) value.value[i];
    }
    return out;
}

istream& operator>>(istream& in, BigInteger &bi){
    string tmpIn;
    in >> tmpIn;
    BigInteger tmpBigInt(tmpIn.c_str());
    bi = tmpBigInt;
    return in;
}

BigInteger& BigInteger::operator=(const BigInteger &val){
    if (this == &val)
        return *this;
    
    if (this->value != NULL)
        delete [] this->value;
    
    this->size = val.size;
    this->value = new short[this->size];
    
    
    for (int i=0; i<this->size; i++) {
        this->value[i] = val.value[i];
    }
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger &x) const{
    
    BigInteger sum(*this);
    string result="";
    
    //get largest size
    long stringSize = (x.size>sum.size ? x.size : sum.size);
    
    ostringstream sumStringConvert;
    
    string sumString;
    
    //get the string of sum
    for (int i = 0; i < sum.size; i++) {
        sumStringConvert << (sum.value[i] -'0');
    }
    
    sumStringConvert.flush();
    sumString = sumStringConvert.str();
    
    //pad with 0
    string padding = padWithZero(stringSize - sumString.length());
    sumString = padding + sumString;
    
    //get the string of x
    
    ostringstream xStringConvert;
    string xString;
    for (int i = 0; i < x.size; i++) {
        xStringConvert << (x.value[i] - '0');
    }
    xStringConvert.flush();
    xString = xStringConvert.str();
    
    //pad with 0
    padding=padWithZero(stringSize - xString.length());
    xString = padding + xString;
    
    //add the 2 strings
    int carry = 0;
    for (long i = stringSize-1; i>=0; i--) {
        int sumstrval = (sumString[i] - '0');
        int xstringval = (xString[i] - '0');
        int sumVal = sumstrval + xstringval + carry;
        carry=0;
        if (sumVal / 10 > 0) {
            carry = sumVal / 10;
            sumVal = sumVal % 10;
        }
        
        ostringstream resultConvert;
        resultConvert << sumVal;
        resultConvert.flush();
        result = resultConvert.str() + result;
        
    }
    
    if (carry != 0) {
        ostringstream carryConvert;
        carryConvert << carry;
        carryConvert.flush();
        result = carryConvert.str() + result;
    }
    
    
    sum.size = result.length();
    delete [] sum.value;
    sum.value = new short [sum.size];
    
    for (int i = 0; i<sum.size; i++) {
        sum.value[i] = result[i];
    }
    
    return sum;
}

BigInteger BigInteger::operator*(const BigInteger& val){
    BigInteger num;
    BigInteger base;
    BigInteger result;
    
    
    if (this->size > val.size) {
        num = *this;
        base = val;
    } else {
        base = *this;
        num = val;
    }
    
    long baseSize = base.size;
    long numSize = num.size;
    
    //declare strings for results (base length);
    string *individualMult = new string[baseSize];
    int addIndvMult = 0;
    for (long i = baseSize-1; i>-1; i--) {
        
        string intermediateRes = "";
        int carry = 0;
        int intRes=0;
        
        int valbase=0;
        int valnum=0;
        
        for (long j = numSize-1; j>-1; j--) {
            valbase = (base.value[i] - '0');
            valnum = (num.value[j] - '0');
            intRes = (valnum * valbase) + carry;
            carry = 0;
            if (intRes/10 > 0) {
                carry = intRes/10;
                intRes = intRes % 10;
            }
            
            ostringstream resultConvert;
            resultConvert << intRes;
            resultConvert.flush();
            intermediateRes = resultConvert.str() + intermediateRes;
        }
        
        //add carry
        if (carry != 0) {
            ostringstream carryConvert;
            carryConvert << carry;
            carryConvert.flush();
            intermediateRes = carryConvert.str() + intermediateRes;
        }
        
        individualMult[addIndvMult] = intermediateRes;
        addIndvMult++;
    }
    
    //add 0s on the end
    for (long i = 1; i < baseSize; i++) {
        individualMult[i] = individualMult[i] + padWithZero(i);
    }
    
    
    //add all values in array
    for (long i = 0; i < baseSize; i++) {
        result = result + BigInteger(individualMult[i].c_str());
    }
    
    delete [] individualMult;
    
    return result;
}

bool BigInteger::operator==(const BigInteger& val){
    if (this->size == val.size) {
        for (int i = 0; i<val.size; i++) {
            if (val.value[i] != this->value[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

string BigInteger::padWithZero(long x) const{
    string ret = "";
    for (long i=0; i<x; i++) {
        ret = ret + "0";
    }
    return ret;
}

void BigInteger::clearStringStream(ostringstream& buffer){
    buffer.str("");
    buffer.clear();
}

