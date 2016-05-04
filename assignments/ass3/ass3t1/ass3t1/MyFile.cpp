//
//  MyFile.cpp
//  ass3t1
//
//  Created by Asjad Athick on 4/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "MyFile.h"

//------------Node

template<class T>
Node<T>::Node(){
    next = NULL;
}

//------------MyList

template<class T>
MyList<T>::MyList(){
    head = NULL;
    tail = NULL;
}

template<class T>
MyList<T>::MyList(const MyList& copy){
    this->head = copy.head;
    this->tail = copy.tail;
}

template<class T>
MyList<T>::~MyList(){
    Node<T> *ptr = head;
    Node<T> *currentPtr;
    
    while (ptr != NULL){
        currentPtr = ptr;
        ptr = ptr->next;
        
        if (currentPtr != NULL)
            delete currentPtr;
    }
}

template<class T>
void MyList<T>::push_front(T item){
    Node<T> *insertItem = new Node<T>;
    insertItem->data = item;
    
    if (!isEmpty()){
        insertItem->next = head;
    } else {
        tail = insertItem;
    }
    
    head = insertItem;
}

template<class T>
T MyList<T>::frontFunction(){
    return head->data;
}

template<class T>
void MyList<T>::pop_front(){
    if (isEmpty())
        return;
    
    Node<T> *deletePointer = head;
    head = head->next;
    
    if (deletePointer == tail)
        tail = NULL;
    
    delete deletePointer;
}

template<class T>
bool MyList<T>::isEmpty(){
    return (head==NULL ? true : false);
}

template<class T>
void MyList<T>::push_back(T item){
    Node<T> *insertItem = new Node<T>;
    insertItem->data = item;
    
    
    if (isEmpty()){
        head = insertItem;
    } else {
        Node<T> *ptr = head;
        Node<T> *prePtr;
        while(ptr != tail){
            prePtr = ptr;
            ptr = ptr->next;
        }
        
        
        ptr->next = insertItem;
    }
    
    tail = insertItem;
    
}

template<class T>
T MyList<T>::backFunction(){
    return tail->data;
}

template<class T>
void MyList<T>::pop_back(){
    if (isEmpty())
        return;
    
    Node<T> *ptr = head;
    Node<T> *prePtr = head;
    while (ptr != tail){
        prePtr = ptr;
        ptr = ptr->next;
    }
    
    if (ptr == head){
        head = NULL;
        tail = NULL;
    } else {
        prePtr->next = NULL;
        tail = prePtr;
    }
    
    delete ptr;
}

