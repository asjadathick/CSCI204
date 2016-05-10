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
	try {
		
		matrix<double> r1(3,3), r2(3,3);
		matrix<complexn> c1(3,3), c2(3,3);
		
		cout << "Input a real matrix (3,3): " << endl;
		cin >> r1;
		cout << "Entered real matrix:" << endl;
		cout << info << r1;
		
		cout << "Input a real matrix (3,3): " << endl;
		cin >> r2;
		cout << "Entered real matrix:" << endl;
		cout << info << r2;
		
		cout << "Sum of real matrix 1 + 2" << endl;
		matrix<double> sumr = r1 + r2;
		cout << noinfo << sumr;
		
		cout << "Difference of real matrix 1 - 2" << endl;
		matrix<double> diffr = r1 - r2;
		cout << noinfo << diffr;
		
		cout << "Product of real matrix 1 * 2" << endl;
		matrix<double> prodr = r1 * r2;
		cout << info << prodr;
		
		cout << "Input a complex matrix (3,3): " << endl;
		cin >> c1;
		cout << "Entered complex matrix:" << endl;
		
		cout << "Input a complex matrix (3,3): " << endl;
		cin >> c2;
		
	} catch (const char* e) {
		cout << "An exception occurred: " << e << endl;
	}
	
	
}
