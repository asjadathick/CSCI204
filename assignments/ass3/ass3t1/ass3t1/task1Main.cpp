//
//  main.cpp
//  ass3t1
//
//  Created by Asjad Athick on 4/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "MyFile.h"

using namespace std;

int main(int argc, const char * argv[]) {
    MyList<int> intList;

    cout << "Push integers 0, ..., 10 to the back of a linked list" << endl;
    for (int i = 0; i < 10; i++) {
        intList.push_back(i);
    }
    cout << "Display integers from the front of the linked list" << endl;
    intList.print(cout);
    
    MyList<char> charList;
    cout << "Push characters A, ..., Z to the back of a linked list" << endl;
    for (char i = 'A'; i <= 'Z'; i++) {
        charList.push_back(i);
    }
    cout << "Display characters from the front of the linked list" << endl;
    charList.print(cout);
    
    cout << "Copy a linked list with characters into another linked list." << endl;
    cout << "Display characters from the front of the copy linked list" << endl;
    MyList<char> charList2(charList);
    charList2.print(cout);
    
    string days[] {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    const int DAY_COUNT = 7;
    MyList<string> stringList;
    cout << "Push strings Monday, ..., Sunday to the back of a linked list" << endl;
    for (int i = 0; i < DAY_COUNT; i++) {
        stringList.push_back(days[i]);
    }
    cout << "Display strings from the front of the linked list" << endl;
    stringList.print(cout);
    
    return 0;
}
