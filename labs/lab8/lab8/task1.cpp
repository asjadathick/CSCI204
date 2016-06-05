//
//  main.cpp
//  lab8
//
//  Created by Asjad Athick on 11/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

class format{
	friend ostream& operator<<(ostream& out, const format& f){
		if (f.base == "oct")
			out << oct;
		
		if (f.base == "hex")
			out << hex;
		
		if (f.base == "dec")
			out << dec;
		
		out << setw(f.length) << setfill(f.pad);
		
		return out;
	}
	
	string base;
	int length;
	char pad;
public:
	format(string prbase, int prlen, char prpad) : base(prbase), length(prlen), pad(prpad){};
};

int main(int argc, const char * argv[]) {
	
	cout << format("oct", 10, '#') << 20 << endl;
	cout << format("hex", 8, '!') << 20 << endl;
	cout << format("dec", 12, '@') << 20 << endl;
    return 0;
}
