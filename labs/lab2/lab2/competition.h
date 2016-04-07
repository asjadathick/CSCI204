//
//  competition.hpp
//  lab2
//
//  Created by mama158, Asjad Athick on 13/03/2016.
//  Student: 4970512
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef competition_h
#define competition_h

#include <iostream>

class Team{
private:
    std::string teamName;
    int totalWin;
    int totalLoss;
    int totalScoreFor;
    int totalScoreAgainst;
public:
    Team();
    Team& operator=(const Team&);
    
    std::string getTeamName();
    void setTeamName(const std::string);
    
    int getTotalWin();
    void incrementTotalWin();
    
    int getTotalLoss();
    void incrementTotalLoss();
    
    int getTotalScoreFor();
    void incrementTotalScoreFor(const int);
    
    
    int getTotalScoreAgainst();
    void incrementTotalScoreAgainst(const int);
};

struct Input{
    std::string team1;
    std::string team2;
    
    int team1Score;
    int team2Score;
    
    int team1Index;
    int team2Index;
};


class Result{

private:
    static const int MAX_SIZE = 10;
    Team dataArray[MAX_SIZE];
    int teamCount;
public:
    Result();
    void loadData(const char*);
    void sortData();
    void printData();
    
    //helper
    int checkTeamInArray(const std::string);
    int addTeamNameInArray(const std::string);
    void initTempStruct(Input&);
};


#endif /* competition_h */
