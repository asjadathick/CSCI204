//
//  Bag.hpp
//  lab7
//
//  Created by Asjad Athick on 3/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef Bag_h
#define Bag_h

#include <iostream>

template<class T>
class Bag{

private:
    int size;
    T *array;
    
public:
    Bag();
    ~Bag();
    void add(T);
    void remove(T);
    Bag<T> operator+(const Bag<T>&);
    friend std::ostream& operator<<(std::ostream& out, const Bag<T>& object){
        out << object.array[0];
        for (int i = 1; i<object.size; i++) {
            out << " " << object.array[i];
        }
        
        return out;
    }
};

#endif /* Bag_h */
