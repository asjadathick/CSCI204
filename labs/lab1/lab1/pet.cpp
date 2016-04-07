//
//  pet.cpp
//  lab1
//
//  Created by Asjad Athick on 9/03/2016.
//  Student: 4970512
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "pet.h"

using namespace std;

//method prototypes
int countRecords(char* fileName);
void loadRecords(char* fileName, Pet* petArray, int size);
void printRecords(Pet* petArray, int size);


int main(){
    cout << "Input File Name: ";
    char fileName[100];
    cin >> fileName;
    
    int records = countRecords(fileName);
    
    cout << "Records loaded: " << records << endl;
    
    Pet *array;
    array = new Pet[records];
    
    loadRecords(fileName, array, records);
    
    printRecords(array, records);
    
    delete [] array;
    
    
    return 0;
}

int countRecords(char* fileName){
    
    //open file
    ifstream inputFile;
    inputFile.open(fileName);
    
    if (!inputFile.good()) {
        cout << "Error opening input file for record count." << endl;
        return 0;
    }
    
    int lineCount=0;
    char temp[200]; //max line length of 200
    
    inputFile.clear();
    inputFile.seekg(ios::beg);
    
    //count
    while (!inputFile.eof()) {
        inputFile.getline(temp, 200,'\n');
        if(!inputFile.eof()){
            if (strcmp(temp, "")!=0) {
                lineCount++;
            }
        }
    }

    
    return lineCount;
}

void loadRecords(char* fileName, Pet* petArray, int size){
    //open file
    ifstream inputFile;
    inputFile.open(fileName);
    
    if (!inputFile.good()) {
        cout << "Error opening input file for record load." << endl;
        return;
    }
    
    char temp[200]; //max line length of 200
    int loadCount=0;
    
    inputFile.clear();
    inputFile.seekg(ios::beg);
    
    while (!inputFile.eof()) {
        inputFile.getline(temp, 200, ',');
        //deal with newline char if any
        if (temp[0]=='\n') {
            for (int i=0; temp[i]!=0; i++) {
                temp[i]=temp[i+1];
            }
        }
        strcpy(petArray[loadCount].status, temp);
        
        inputFile.getline(temp, 200, ',');
        strcpy(petArray[loadCount].petType, temp);
        
        inputFile.getline(temp, 200, ',');
        strcpy(petArray[loadCount].gender, temp);
        
        inputFile.getline(temp, 200, ',');
        strcpy(petArray[loadCount].breed, temp);
        
        inputFile.getline(temp, 200, ' ');
        petArray[loadCount].ageYear = atoi(temp);
        
        inputFile.getline(temp, 200, ',');
        petArray[loadCount].ageMonth = atoi(temp);
        
        inputFile.getline(temp, 200, ',');
        strcpy(petArray[loadCount].color, temp);
        
        inputFile.getline(temp, 200, ',');
        petArray[loadCount].chipNumber = atol(temp);
        
        inputFile.getline(temp, 200, ',');
        strcpy(petArray[loadCount].location, temp);
        
        inputFile.getline(temp, 200, '\n');
        strcpy(petArray[loadCount].contactPhone, temp);
        
        if (!inputFile.eof()) {
            loadCount++;
        }

    }
    
    if (loadCount != size) {
        cout << "Error loading data. The number of records loaded did not match the size passed in" << endl;
    }

}

void printRecords(Pet* petArray, int size){
    for (int i = 0; i < size; i++) {
        cout << petArray[i].status << ", " << petArray[i].petType << ", " << petArray[i].gender << ", " << petArray[i].breed << ", " << petArray[i].ageYear << ", " << petArray[i].ageMonth << ", " << petArray[i].color << ", " << petArray[i].chipNumber << ", " << petArray[i].location << ", " << petArray[i].contactPhone << endl;
    }
}
