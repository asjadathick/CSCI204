//
//  pet.hpp
//  lab1
//
//  Created by Asjad Athick on 9/03/2016.
//  //  Student: 4970512
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef pet_h
#define pet_h

struct Pet{
    char status[8];
    char petType[15];
    char gender[8];
    char breed[20];
    unsigned int ageYear;
    unsigned int ageMonth;
    char color[20];
    unsigned long chipNumber;
    char location[30];
    char contactPhone[9];
};

#endif /* pet_hpp */
