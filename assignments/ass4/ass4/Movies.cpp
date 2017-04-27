//
//  Movies.cpp
//  ass4
//
//  Created by Asjad Athick on 5/06/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

struct MovieInfo{
	int total;
	int ratingsCount;
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

float average(vector<int> v){
	float avg = 0;
	for (int i = 0; i < v.size(); i++) {
		avg += v.at(i);
	}
	avg/= v.size();
	return avg;
}

int main(int argc, const char * argv[]) {
	map<string,vector<int> > ratings;
	
	//for each rating file
	for (int i = 1; i < argc; i++) {
		ifstream input;
		if (!openFile(argv[i], input)){
			cout << "Could not open " << argv[i] << endl;
			continue;
		}
		
		string buffer;
		int ratingCount = 0;
		getline(input, buffer, '\n');
		
		ratingCount = atoi(buffer.c_str());
		
		string movieName;
		int rating;
		
		for (int j = 0; j < ratingCount; j++) {
			getline(input, buffer, '\n');
			movieName = buffer.substr(0,buffer.size()-1); //get rid of \n
			
			getline(input, buffer, '\n');
			rating = atoi(buffer.c_str());
			
			if (rating <1 || rating > 5){
				cout << "Invalid rating for movie " << movieName << endl;
				continue;
			}
			
			ratings[movieName].push_back(rating);
		}
	}
	
	map<string,vector<int> >::iterator it;
	
	//output movies and average
	for (it = ratings.begin(); it != ratings.end(); it++) {
		cout << it->first << ": " << it->second.size() << (it->second.size()>1 ? " reviews " : " review ") << setprecision(2) << average(it->second) << "/5" << endl;
	}
	
	return 0;
}
