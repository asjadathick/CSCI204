//
//  main.cpp
//  lab9
//
//  Created by Asjad Athick on 17/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Student.h"
using namespace std;

std::istream& operator>>(std::istream& ins, Student& stud);
std::ostream& operator<<(std::ostream& outs, Student& stud);

template<class T>
string toString(T value){
	ostringstream s;
	s << value;
	
	return s.str();
}

template<class T>
T toValue(string str){
	T val;
	istringstream iss;
	iss.str(str);
	iss >> val;
	return val;
}


std::istream& operator>>(std::istream& ins, Student& stud){
	while (ins.peek() == '\n') {
		ins.ignore();
	}
	
	string buffer;
	getline(ins, stud.firstname, ':');
	getline(ins, stud.lastname, ':');
	getline(ins, buffer, ':');
	stud.id = toValue<int>(buffer);
	getline(ins, buffer, '\n');
	stud.gpa = toValue<float>(buffer);
	return ins;
}

std::ostream& operator<<(std::ostream& outs, Student& stud){
	outs << stud.firstname << ":" << stud.lastname << ":" << stud.id << ":" << stud.gpa;
	return outs;
}


int main(int argc, const char * argv[]) {
	cout << "Input an integer: ";
	int i1;
	cin >> i1;
	
	cout << "Integer to string: " << toString(i1) << endl;
	cout << "String to integer " << toValue<int>(toString(i1)) << endl;
	
	cout << "Input a double: ";
	double d1;
	cin >> d1;
	
	cout << "Double to string: " << toString(d1) << endl;
	cout << "String to Double " << toValue<double>(toString(d1)) << endl;
	
	cout << "Input a student record (first-name:last-name:number:gpa): ";
	Student s1;
	cin >> s1;
	
	cout << "Student to string: " << toString(s1) << endl;
	
	Student s2;
	s2 = toValue<Student>(toString(s1));
	cout << "String to Student:" << s2 << endl;
	
	return 0;
}
