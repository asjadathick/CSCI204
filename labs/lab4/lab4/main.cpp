//
//  main.cpp
//  lab4
//
//  mama158
//  Created by Asjad Athick on 2/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "BigInteger.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Input a big integer for bi1: ";
    string bi1;
    getline(cin, bi1, '\n');
    
    cout << "Input a big integer for bi2: ";
    string bi2;
    getline(cin, bi2, '\n');
    
    BigInteger b1(bi1.c_str());
    BigInteger b2(bi2.c_str());
    BigInteger b3("1234567890");
    
    cout << "Initial bi3=" << b3 << endl;
    
    b3 = b1 + b2;
    
    cout << "bi3 = bi1 + bi2 = " << b3 << endl;
    
    b3 = b1 * b2;
    
    cout << "bi3 = bi1 * bi2 = " << b3 << endl;
    
    if (b1 == b2) {
        cout << "bi1 is equal to bi2" << endl;
    } else {
        cout << "bi1 is not equal to bi2" << endl;
    }
    
    BigInteger temp1("882323456205024318310561095");
    b3 = b2 = temp1;
    
    
    cout << "bi3 = bi2 = 882323456205024318310561095" << endl;
    
    if (b3 == b2) {
        cout << "bi3 is equal to bi2" << endl;
    } else {
        cout << "bi3 is not equal to bi2" << endl;
    }
     
    
    return 0;
}
