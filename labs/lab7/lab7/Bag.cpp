//
//  Bag.cpp
//  lab7
//
//  Created by Asjad Athick on 3/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "Bag.h"

template<class T>
Bag<T>::Bag(){
    size = 0;
    array = new T[size];
}

template<class T>
Bag<T>::~Bag(){
    if (array != NULL) {
        delete [] array;
    }
}

template<class T>
void Bag<T>::add(T item){
    //resize array
    size++;
    T *newArray = new T[size];
    
    for (int i = 0; i < size - 1; i++) {
        newArray[i] = array[i];
    }
    
    newArray[size-1] = item;
    
    if (array != NULL){
        delete [] array;
    }
    
    array = newArray;
}


template<class T>
void Bag<T>::remove(T item){
    int deleteIndex=-1;
    for (int i = 0; i < size; i++) {
        if (array[i] == item){
            deleteIndex = i;
            break;
        }
    }
    
    T *newArray = new T[size-1];
    
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (i != deleteIndex){
            newArray[cnt] = array[i];
            cnt++;
        }
    }
    
    size--;
    
    if (array != NULL)
        delete [] array;
    
    array = newArray;
    
}

template<class T>
Bag<T> Bag<T>::operator+(const Bag<T>& value){
    
    Bag<T> returnBag;
    returnBag.size = this->size + value.size;
    
    T *newArray = new T[returnBag.size];
    
    int counter;
    
    for (counter = 0; counter < this->size; counter++) {
        newArray[counter] = this->array[counter];
    }
    
    for (int i = 0; i < value.size; i++) {
        newArray[counter] = value.array[i];
        counter++;
    }
    
    if (returnBag.array != NULL){
        delete [] returnBag.array;
    }
    
    returnBag.array = newArray;
    
    return returnBag;
}
