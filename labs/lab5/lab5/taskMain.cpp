//
//  main.cpp
//  lab5
//
//  Created by Asjad Athick on 10/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include "Bank.h"

int main(int argc, const char * argv[]) {
    
    Saving aliceAccount("123456", "12345678", "Alice", "1 Northfields Avenue, Wollongong", "1234567", 1000, "1234567890123456");
    
    Credit bobAccount("123123", "12341234", "Bob", " 20 Moore Street, North Wollongong", "12341234", 1000, "0987654321123456", 2000, 15);
    
    aliceAccount.interest();
    bobAccount.interest();
    
    std::cout << aliceAccount << '\n' << bobAccount << std::endl;
    
    return 0;
}
