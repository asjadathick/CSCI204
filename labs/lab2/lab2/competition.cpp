//
//  competition.cpp
//  lab2
//
//  Created by mama158, Asjad Athick on 13/03/2016.
//  Student: 4970512
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "competition.h"
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Team Class

Team::Team(){
    //initialise
    teamName = "";
    totalWin = 0;
    totalLoss = 0;
    totalScoreFor = 0;
    totalScoreAgainst = 0;
}

string Team::getTeamName(){
    return teamName;
}

void Team::setTeamName(const string value){
    teamName = value;
}

int Team::getTotalWin(){
    return totalWin;
}

void Team::incrementTotalWin(){
    totalWin++;
}

int Team::getTotalLoss(){
    return totalLoss;
}

void Team::incrementTotalLoss(){
    totalLoss++;
}

int Team::getTotalScoreFor(){
    return totalScoreFor;
}

void Team::incrementTotalScoreFor(const int value){
    totalScoreFor += value;
}

int Team::getTotalScoreAgainst(){
    return totalScoreAgainst;
}

void Team::incrementTotalScoreAgainst(const int value){
    totalScoreAgainst += value;
}

Team& Team::operator=(const Team& value){
    this->teamName = value.teamName;
    this->totalWin = value.totalWin;
    this->totalLoss = value.totalLoss;
    this->totalScoreFor = value.totalScoreFor;
    this->totalScoreAgainst = value.totalScoreAgainst;
    
    return *this;
}

//Result Class

Result::Result(){
    teamCount = 0;
}

void Result::initTempStruct(Input& temp){
    temp.team1 = "";
    temp.team1Index = 0;
    temp.team1Score = 0;
    temp.team2 = "";
    temp.team2Index = 0;
    temp.team2Score = 0;
}

void Result::loadData(const char* fileName){
    ifstream inputFile;
    inputFile.open(fileName);
    
    if (!inputFile.good()) {
        cout << "Error opening file to load data.";
        return;
    }
    
    inputFile.clear();
    inputFile.seekg(ios::beg);
    
    while (!inputFile.eof()) {
        Input temp;
        initTempStruct(temp);
        
        string buffer;
        
        getline(inputFile, temp.team1, ':');
        getline(inputFile, temp.team2, '\n');
        
        if (inputFile.good()) {
            
            getline(inputFile, buffer, ':');
            temp.team1Score = atoi(buffer.c_str());
            
            getline(inputFile, buffer, '\n');
            temp.team2Score = atoi(buffer.c_str());
            
            
            //analyse
            
            //Check if Team1 in array
            temp.team1Index = checkTeamInArray(temp.team1);
            if (temp.team1Index == -1) {
                temp.team1Index = addTeamNameInArray(temp.team1);
                if (temp.team1Index == -1) {
                    cout << "Array is full. Could not add team " << temp.team1 << " into the array." << endl;
                }
            }
            
            //Check if Team2 in array
            temp.team2Index = checkTeamInArray(temp.team2);
            if (temp.team2Index == -1) {
                temp.team2Index = addTeamNameInArray(temp.team2);
                if (temp.team2Index == -1) {
                    cout << "Array is full. Could not add team " << temp.team2 << " into the array." << endl;
                }
            }
            
            //decide win
            if (temp.team1Score > temp.team2Score) {
                dataArray[temp.team1Index].incrementTotalWin();
                dataArray[temp.team2Index].incrementTotalLoss();
                
            } else {
                dataArray[temp.team2Index].incrementTotalWin();
                dataArray[temp.team1Index].incrementTotalLoss();
            }
            
            dataArray[temp.team1Index].incrementTotalScoreFor(temp.team1Score);
            dataArray[temp.team1Index].incrementTotalScoreAgainst(temp.team2Score);
            
            dataArray[temp.team2Index].incrementTotalScoreFor(temp.team2Score);
            dataArray[temp.team2Index].incrementTotalScoreAgainst(temp.team1Score);
            
            
        }
    }
}

void Result::sortData(){
    //insertion sort
    int i, j;
    Team next;
    for (i = 1; i < teamCount; i++){
        next = dataArray[i];
        j = i;
        while (j > 0 && (((next.getTotalWin() > dataArray[j-1].getTotalWin()) && (next.getTotalWin() != dataArray[j-1].getTotalWin())) || ((next.getTotalLoss() < dataArray[j-1].getTotalLoss()) && (next.getTotalLoss() != dataArray[j-1].getTotalLoss())) || (next.getTotalScoreFor() - next.getTotalScoreAgainst()) > (dataArray[j-1].getTotalScoreFor() - dataArray[j-1].getTotalScoreAgainst()))) {
            dataArray[j] = dataArray[j-1];
            j--;
        }
        dataArray[j] = next;
    }
}

void Result::printData(){
    for (int i=0; i<teamCount; i++) {
        cout << setw(20) << left << dataArray[i].getTeamName()  << dataArray[i].getTotalWin() << '\t' << dataArray[i].getTotalLoss() << '\t' << dataArray[i].getTotalScoreFor() << '\t' << dataArray[i].getTotalScoreAgainst() << endl;
    }
}

int Result::checkTeamInArray(const string teamName){
    
    for (int i = 0; i<teamCount; i++) {
        if (dataArray[i].getTeamName() == teamName) {
            return i;
        }
    }
    
    return -1;
}

int Result::addTeamNameInArray(const string teamName){
    if (teamCount >= MAX_SIZE) {
        return -1;
    }
    
    dataArray[teamCount].setTeamName(teamName);
    teamCount++;
    
    return (teamCount-1);
}
