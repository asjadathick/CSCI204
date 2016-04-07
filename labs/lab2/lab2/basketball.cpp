//
//  main.cpp
//  lab2
//
//  Created by mama158, Asjad Athick on 13/03/2016.
//  Student: 4970512
//  Copyright © 2016 Asjad Athick. All rights reserved.
//


#include <iostream>
#include "competition.h"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Input a basketball competition results' file name: ";
    char fileName[200];
    cin>>fileName;
    
    Result result;
    result.loadData(fileName);
    result.sortData();
    result.printData();
    
    return 0;
}
