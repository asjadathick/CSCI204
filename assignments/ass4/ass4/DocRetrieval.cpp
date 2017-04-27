//
//  main.cpp
//  ass4
//
//  Created by Asjad Athick on 1/06/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

struct Document{
	string documentName;
	vector<string> words;
	float coefficient;
};

bool openFile(string filename, ifstream& in){
	in.open(filename.c_str());
	if (in.good()){
		return true;
	} else {
		cout << "Error opening file: " << filename << endl;
		return false;
	}
}

bool isValid(char value){
	if (((value >= 'a') && (value <= 'z')) || ((value >= '0') || (value <= '9')))
		return true;
	return false;
}

string sanitise(string input){
	string result;
	for (int i = 0; i < input.size(); i++) {
		if (isalnum(tolower(input.at(i)))){
			result += tolower(input.at(i));
		}
	}
	return result;
}

bool loadWordsFromDocument(Document &doc){
	//open file
	ifstream file;
	if (!openFile(doc.documentName, file)){
		return false;
	}
	
	//get words into doc vector
	string buffer;
	while (file >> buffer) {
		doc.words.push_back(sanitise(buffer));
	}
	
	return true;
}

int intersection(vector<string> v1, vector<string> v2){
	vector<string> intersect;
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intersect));
	
	return (int)intersect.size();
}

float calculateCoefficient(Document data, Document query){
	float coefficient = 0;
	coefficient = intersection(data.words, query.words) / (sqrt((double)(data.words.size())) * (sqrt((double)(query.words.size())))) ;
	
	return coefficient;
}

bool compareDocuments(Document d1, Document d2){
	return d1.coefficient > d2.coefficient;
}

string first10Words(string filename){
	string result;
	
	ifstream inputFile;
	if (!openFile(filename, inputFile))
		return "File open error.";
	
	int count = 0;
	string buffer;
	while (inputFile >> buffer) {
		result += (buffer) + " ";
		count++;
		if (count >= 10)
			break;
	}
	
	if (inputFile >> buffer) {
		result += " ...";
	}
	
	return result;
}

int main(int argc, const char * argv[]) {
	//get doc list
	vector<Document> documents;
	ifstream docList;
	if (!openFile("listofdocs.txt", docList)) {
		return -1;
	}
	
	string buffer;
	Document tempStruct;
	tempStruct.coefficient = 0;
	
	while (!docList.eof()) {
		getline(docList, buffer, '\n');
		if (!docList.eof()){
			tempStruct.documentName = buffer;
			documents.push_back(tempStruct);
		}
	}
	
	for (int i = 0; i < documents.size(); i++) {
		loadWordsFromDocument(documents.at(i));
	}
	
	//get words from query
	Document query;
	for (int i = 1; i < argc; i++) {
		query.words.push_back(sanitise(argv[i]));
	}
	
	//calculate coefficients
	for (int  i = 0; i < documents.size(); i++) {
		documents.at(i).coefficient = calculateCoefficient(documents.at(i), query);
	}
	
	//sort document vector
	sort(documents.begin(), documents.end(), compareDocuments);
	
	//output documents
	
	for (int i = 0; i < documents.size(); i++) {
		cout << "(" << documents.at(i).documentName << " - " << fixed << setprecision(2) << (documents.at(i).coefficient * 100) << "%) " <<
		first10Words(documents.at(i).documentName) << endl << endl;
	}
	
    return 0;
}
