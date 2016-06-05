//
//  main.cpp
//  t2
//
//  Created by Asjad Athick on 11/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "Image.h"

using namespace std;

int main(int argc, const char * argv[]) {
	try {
		if (argc != 2) {
			throw "Incorrect number of arguments. Main";
		}
		
		Image im1(argv[2]);
		im1.getStats();
		
	} catch (const char* e) {
		cout << "Exception: " << e << endl;
	}
	
    return 0;
}
