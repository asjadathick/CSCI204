//
//  MyFile.hpp
//  ass3t1
//
//  Created by Asjad Athick on 4/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef MyFile_h
#define MyFile_h

#include <iostream>


template <class T>
class Node {
    template<class U>
    friend class MyList;
    T data;
    Node *next;
public:
    Node();
};

template <class T>
class MyList {
    Node<T> *head;
    Node<T> *tail;
public:
    MyList();
    MyList(const MyList&);
    ~MyList();
    void push_front(T);
    void push_back(T);
    bool isEmpty();
    T frontFunction();
    T backFunction();
    void pop_front();
    void pop_back();
    
};

#endif /* MyFile_hpp */
