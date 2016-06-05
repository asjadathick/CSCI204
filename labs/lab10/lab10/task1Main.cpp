//
//  main.cpp
//  lab10
//
//  Created by Asjad Athick on 24/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isValid(char val){
	if ((toupper(val) >= 'A' && toupper(val) <='Z') || (val >='0' && val <='9')) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, const char * argv[]) {
	int validCharCount = 0;
	char input;
	vector<char> vec;
	while (!cin.eof()) {
		input = cin.get();
		if (!cin.eof()){
			vec.push_back(input);
			if (isValid(input)) {
				validCharCount++;
			}
		}
	}
	
	vector<char>::iterator startIt = vec.begin();
	vector<char>::iterator endIt = vec.end();
	endIt--;
	
	bool valid = true;
	int count = 0;
	
	while (count <= validCharCount && valid ) {
		//position start
		while (!isValid(*startIt) && startIt  != vec.end()) {
			++startIt;
		}
		
		//position end
		while (!isValid(*endIt) && endIt != vec.begin()) {
			--endIt;
		}
		
		if (startIt == vec.end() || endIt == vec.begin()) {
			break;
		}
		
		if (tolower(*startIt) != tolower(*endIt)) {
			valid = false;
		}
		
		startIt++;
		endIt--;
		validCharCount++;
	}
	
	cout << "\"";
	for (vector<char>::iterator i = vec.begin(); i != vec.end(); i++) {
		cout << *i;
	}
	cout << "\"";
	
	if (valid) {
		cout << " is a palindrome" << endl;
	} else {
		cout << " is not a palindrome" << endl;
	}
	
    return 0;
}
