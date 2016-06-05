#include <algorithm>
#include <iterator>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

typedef map<int, string>::iterator mapit;
typedef map<int, string> maptype;

// task one (a)
void populatemap(maptype& taxrecords, ifstream& ins)
{
	if (!ins.good()) {
		cout << "Could not open file" << endl;
		return;
	}
	
	int key;
	string buffer;
	while (!ins.eof()) {
		getline(ins, buffer, ' ');
		key = atoi(buffer.c_str());
		getline(ins, buffer, '\n');
		taxrecords[key] = buffer;
	}
}

// Task one (b) 
mapit findrecord(maptype& taxrecords, int key)
{
	mapit ret = taxrecords.find(key);
	return ret;
}

//

//void printout(pair<int, string>);
int main()
{
	ifstream ins;
	maptype	taxrecords;
	int byte_size = 0, no_rec = 0;
	ins.open("ato.txt", ios::in);

	populatemap(taxrecords, ins);
	
	ins.close();
	// output the number of records in the map
	cout<<"The total number of records is " << taxrecords.size();
	
	//find
	mapit mit;
	int tfn = 212221;
	cout<<endl;
	cout << "Find the person whose TFN is "<<tfn<<endl;
	mit = findrecord(taxrecords, tfn);
	if(mit != taxrecords.end())
	{
		cout<< mit->first << "->" << mit->second <<endl;
	}
	else
	{
		cout << "Not find"<< endl;
	}
	cout<<endl;
	tfn = 9999;
	cout << "Find the person whose TFN is "<<tfn<<endl;
	mit = findrecord(taxrecords, tfn);
	if(mit != taxrecords.end())
	{
		cout<< mit->first << "->" << mit->second <<endl;
	}
	else
	{
		cout << "Not find"<< endl;
	}

	
	return 0;
}


