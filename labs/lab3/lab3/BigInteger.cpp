//
//  BigInteger.cpp
//  lab3
//
//  Created by Asjad Athick on 21/03/2016.
//  Student: mama158
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "BigInteger.h"
#include <string>
#include <sstream>
using namespace std;

//BigInteger

BigInteger::BigInteger(){
    size = 1;
    value = new short [size];
    value[0]='0';
}

BigInteger::~BigInteger(){
    delete [] value;
}

BigInteger::BigInteger(long long int v){
    ostringstream convert;
    convert << v;
    string val = convert.str();
    this->size = val.length();
    
    this->value = new short int [size];
    memset(this->value, '0', this->size);
    
    for (int i=0; i<this->size; i++) {
        this->value[i] = val[i];
    }
}

BigInteger::BigInteger(char* array){
    //null terminator expected at end of char array
    this->size=strlen(array);
    this->value = new short[this->size-1];
    
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

BigInteger BigInteger::add(BigInteger x){
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
    xString = xStringConvert.str();
    
    //pad with 0
    padding=padWithZero(stringSize - xString.length());
    xString = padding + xString;
    
    //add the 2 strings
    int carry = 0;
    for (long i = stringSize-1; i>=0; i--) {
        int sumVal = (sumString[i] - '0') + (xString[i] - '0') + carry;
        carry=0;
        if (sumVal / 10 > 0) {
            carry = sumVal / 10;
            sumVal = sumVal % 10;
        }
        
        ostringstream resultConvert;
        resultConvert.flush();
        resultConvert << sumVal;
        result = resultConvert.str() + result;
        
    }
    
    if (carry != 0) {
        ostringstream carryConvert;
        carryConvert.flush();
        carryConvert << carry;
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

void BigInteger::print(ostream& out){
    for (int i = 0; i<this->size; i++) {
        out << (char) this->value[i];
    }
    out << endl;
}

string BigInteger::padWithZero(long x){
    string ret = "";
    for (long i=0; i<x; i++) {
        ret = ret + "0";
    }
    return ret;
}

