//
//  main.cpp
//  ass3t2
//
//  Created by Asjad Athick on 7/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "matrix.h"
#include "matrix.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "M1: " << endl;
    matrix<int> m1(3,3);
    cin >> m1;
    cout << m1;
    
    cout << "M2: " << endl;
    matrix<int> m2(3,3);
    cin >> m2;
    cout << m2;
    
    matrix<int> m3 = m1 + m2;
    cout << "M3:\n" << m3;
    
    matrix<int> m4 = m1-m2;
    cout << "M4:\n" << m4;
    
    matrix<int> m5 = m1 * m2;
    cout << "M5:\n" << m5;
    
    /*complexn c1, c2;
    
    cin >> c1;
    
    cin >> c2;
    
    complexn c3 = c1 + c2;
    complexn c4 = c1 - c2;
    complexn c5 = c1 * c2;
    
    cout << complexn::real << c1;
    cout << complexn::magnitude << c2;
    cout << complexn::cplx << c3 << c4 << c5;*/
}
