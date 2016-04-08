//
//  main.cpp
//  ass2
//
//  mama158
//  Created by Asjad Athick on 3/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "EVector.h"
using namespace std;

int main(int argc, const char * argv[]) {
    EVector v1;
    cout << "Input dimension and tuples for a Euclidean vector v1: ";
    cin >> v1;
    cout << "Euclidean vector v1 = (" << v1 << ")" << endl;
    
    EVector v2;
    cout << "\nInput dimension and tuples for a Euclidean vector v2: ";
    cin >> v2;
    cout << "Euclidean vector v2 = (" << v2 << ")" << endl;
    
    EVector v3;
    v3 = v1 + v2;
    cout << "\nv3 = v1 + v2 = (" << v3 << ")" << endl;
    v3 = v1 - v2;
    cout << "v3 = v1 - v2 = (" << v3 << ")" << endl;
    cout << "v3 = v1 * v2 = (" << v1 * v2 << ")" << endl;
    
    cout << "\nInput a double value for d:";
    double val;
    cin >> val;
    
    v3 = val * v1;
    cout << "\nd * v1 = " << val << " * " << v1 << ") = (" << val * v1 << ")" << endl;
    v3 = v1 * val;
    cout << "\nv1 * d = " << v1 << " * " << val << ") = (" << v1 * val << ")" << endl;
    v3 = v1/val;
    cout << "\nv1 / d = " << v1 << " / " << val << ") = (" << v1 / val << ")" << endl;
    
    return 0;
}
