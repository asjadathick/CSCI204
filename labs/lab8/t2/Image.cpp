//
//  Image.cpp
//  lab8
//
//  Created by Asjad Athick on 11/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "Image.h"
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;


//------Image
Image::Image(string fileName){
	width = 0;
	height = 0;
	minIntensity = 0;
	maxIntensity = 0;
	avgIntensity = 0;
	
	ifstream imgFile;
	imgFile.open(fileName.c_str());
	
	if (!imgFile.good()) {
		throw "Could not open file";
	}
	
	//validate if P5
	string magicNumber;
	getline(imgFile, magicNumber, '\n');
	
	if (magicNumber != "P5") {
		throw string("<" + fileName + "> is not a PGM file").c_str();
	}
	
	//ignore comments
	string buffer;
	getline(imgFile, buffer, '\n');
	while (buffer.at(0) == '#'){
		getline(imgFile, buffer, '\n');
	}
	
	int pos = (int)buffer.find(" ");
	width = atoi(buffer.substr(0, pos).c_str());
	height = atoi(buffer.substr(pos+1).c_str());
	
	imgFile >> maxIntensity;
	
	if (!((maxIntensity > 0) && (maxIntensity < 65536))) {
		throw "Max intensity > 65536";
	}
	
	int count = 0;
	long valsum = 0;
	minIntensity = maxIntensity;
	maxIntensity = 0;
	
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			unsigned char value;
			value = static_cast<unsigned short>(imgFile.get()) + 128;
			
			valsum += value;
			count++;
		}
	}
	
	avgIntensity = (valsum / 1.0) / (count);
	
	imgFile.close();
	cout << "Read a gray-scale image from a PGM file <" << fileName << ">." << endl;
}


void Image::getStats(){
	cout << "Statistics of the image:" << endl;
	cout << setw(15) << left << "Width:" << width << endl;
	cout << setw(15) << left << "Height:" << height << endl;
	cout << setw(15) << left << "Min-Intensity:" << minIntensity << endl;
	cout << setw(15) << left << "Max-Intensity:" << maxIntensity << endl;
	cout << setw(15) << left << "Ave-Intensity:" << avgIntensity << endl;
}
