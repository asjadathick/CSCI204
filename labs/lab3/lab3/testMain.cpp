//
//  main.cpp
//  lab3
//
//  Created by Asjad Athick on 21/03/2016.
//  Student: mama158
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "BigInteger.h"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Test wth long long initialisation:\nInputs:\n" << endl;
    BigInteger a1(1);
    a1.print(cout);
    
    BigInteger a2(322375807);
    a2.print(cout);
    
    BigInteger asum= a2.add(a1);
    
    cout << "Sum: ";
    asum.print(cout);
    cout << "\nTest with char array initialisation\nInputs:\n" << endl;
    
    char number[125];
    strcpy(number, "999900887976456435338548456374526533456468567855678454634354637356856488548658564563543748584576457694856465363673734374457");
    BigInteger b1(number);
    b1.print(cout);
    
    BigInteger b2(1);
    b2.print(cout);
    
    BigInteger bsum = b2.add(b1);
    cout << "Sum: ";
    bsum.print(cout);
    
    cout << "\nTest with copy constructor:\nInputs:\n" << endl;
    BigInteger c1(999999);
    c1.print(cout);
    BigInteger c2(c1);
    c2.print(cout);
    BigInteger c3 = c1.add(c2);
    cout << "Sum: ";
    c3.print(cout);
    
    cout << "\nTest with default constructor:\nInputs:\n" << endl;
    BigInteger d1;
    d1.print(cout);
    BigInteger d2(10);
    d2.print(cout);
    BigInteger d3 = d1.add(d2);
    cout << "Sum: ";
    d3.print(cout);

}
