//
//  main.cpp
//  ass3t1
//
//  Created by Asjad Athick on 4/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "MyFile.h"
#include "MyFile.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    MyList<int> intList;
    intList.push_front(1);
    intList.push_front(2);
    
    cout << intList.frontFunction() << endl;
    intList.pop_front();
    
    cout << intList.frontFunction() << endl;
    intList.pop_front();
    
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    
    cout << intList.backFunction() << endl;
    intList.pop_back();
    
    cout << intList.backFunction() << endl;
    intList.pop_back();
    
    cout << intList.backFunction() << endl;
    intList.pop_back();
    
    return 0;
}
