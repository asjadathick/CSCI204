//
//  vectorCompare.cpp
//  lab9
//
//  Created by Asjad Athick on 18/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool exists_in_vector(vector<int>& a, int val);
void remove_duplicates(vector<int>& a);
bool same_elements(vector<int> a, vector<int>b);
void printVector(vector<int> a);

int main(){
	
	int int1[] = {1,4,9,16,9,7,4,9,11};
	vector<int> f1(int1, int1 + sizeof(int1) / sizeof(int));
	
	int int2[] = {11, 1, 4, 9, 16, 9, 7, 4, 9};
	vector<int> f2(int2, int2 + sizeof(int2) / sizeof(int));
	
	int int3[] = {11, 11, 7, 9, 16, 4, 1};
	vector<int> f3(int3, int3 + sizeof(int3) / sizeof(int));
	
	cout << "Vector comparison: " << endl;
	cout << "F1: ";
	printVector(f1);
	
	cout << "F2: ";
	printVector(f2);
	
	cout << "F3: ";
	printVector(f3);
	
	if (same_elements(f1, f2))
		cout << "F1 is the same as F2" << endl;
	else
		cout << "F1 is NOT the same as F2" << endl;
	
	
	if (same_elements(f1, f3))
		cout << "F1 is the same as F3" << endl;
	else
		cout << "F1 is NOT the same as F3" << endl;
	
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v1.push_back(i);
	}
	
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v1.push_back(i);
	}
	
	cout << "\nV1 before removing duplicates: " << endl;
	printVector(v1);
	
	remove_duplicates(v1);
	cout << "V1 after removing duplicates: " << endl;
	printVector(v1);
	
	
	return 0;
}

void printVector(vector<int> a){
	for (int i = 0; i < a.size(); i++) {
		cout << a.at(i) << " ";
	}
	
	cout << endl;
}

bool same_elements(vector<int> a, vector<int>b){
	if (a.size() != b.size())
		return false;
	
	int same = 0;
	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i) == b.at(j)) {
			same++;
		} else {
			same = 0;
			i--;
		}
		
		j++;
		
		if (j >= b.size())
			j = 0;
		
		if (same == a.size()) {
			return true;
		}
	}
	
	return false;
}

void remove_duplicates(vector<int>& a){
	vector<int> checked;
	
	for (int i = 0; i < a.size(); i++) {
		if (exists_in_vector(checked, a.at(i))){
			a.erase(a.begin() + i);
			i--;
		} else {
			checked.push_back(a.at(i));
		}
	}
}

bool exists_in_vector(vector<int>& a, int val){
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i) == val)
			return true;
	}
	return false;
}
