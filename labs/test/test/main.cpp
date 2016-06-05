#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string buffer = "Hello 123";
	int value = 0;
	for (int i = 0; i<buffer.length(); i++){
		if (buffer[i] >= '0' && buffer[i] <='9'){
			value = atoi(buffer.substr(i).c_str());
			break;
		}
	}
	
	cout << value << endl;
	
	ifstream in;
	in.open("../../../../../../../../Documents/CSCI204/labs/test/test/test.txt");
	
	if (!in.good()) {
		cout << "Error opening file" << endl;
		return -1;
	}
	
	int numlines = 0;
	
	while (!in.eof()) {
		getline(in, buffer);
		numlines++;
		
	}
	
	in.close();
	
	int *array = new int[numlines];
	
	ofstream out;
	out.open("../../../../../../../../Documents/CSCI204/labs/test/test/testout.txt");
	
	if (!out.good()) {
		cout << "Error opening file for out" << endl;
	}
	
	out << "Hey\nMy name is \n Jesse" << endl;
	
	out.close();
	
	cout << "NumLines:" << numlines << endl;
	
	return 0;
}