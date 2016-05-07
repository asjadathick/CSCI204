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
    Node(){
        next = NULL;
    }
};

template <class T>
class MyList {
    Node<T> *head;
    Node<T> *tail;
public:
    MyList(){
        head = NULL;
        tail = NULL;
    }
    
    MyList(const MyList& copy){
        Node<T> *ptr = copy.head;
        while (ptr != NULL){
            push_back(ptr->data);
            ptr = ptr->next;
        }
    }
    
    ~MyList(){
        Node<T> *ptr = head;
        Node<T> *currentPtr;
        
        while (ptr != NULL){
            currentPtr = ptr;
            ptr = ptr->next;
            
            if (currentPtr != NULL)
                delete currentPtr;
        }
    }
    
    void push_front(T item){
        Node<T> *insertItem = new Node<T>;
        insertItem->data = item;
        
        if (!isEmpty()){
            insertItem->next = head;
        } else {
            tail = insertItem;
        }
        
        head = insertItem;
    }
    
    void push_back(T item){
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
    
    bool isEmpty(){
        return (head==NULL ? true : false);
    }
    
    T frontFunction(){
        return head->data;
    }
    
    T backFunction(){
        return tail->data;
    }
    
    void pop_front(){
        if (isEmpty())
            return;
        
        Node<T> *deletePointer = head;
        head = head->next;
        
        if (deletePointer == tail)
            tail = NULL;
        
        delete deletePointer;
    }
    
    void pop_back(){
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
    
    class Iterator;
    friend class Iterator;
    
    class Iterator{
        Node<T> *current;
        Node<T> *last;
    public:
        Iterator(MyList& list) : current(list.head), last(list.tail) {};
        Iterator(MyList& list, bool) : current(list.tail), last(list.tail) {};
        
        T operator*(){
            return current->data;
        }
        
        Node<T>* operator++(int value){
            if (current != NULL)
                current = current->next;
            return current;
        }
        
        bool operator != (const Iterator &other) const{
            if (this->current != other.current->next)
                return true;
            else
                return false;
        }
    };
    
    Iterator begin(){
        return Iterator(*this);
    }
    
    Iterator end(){
        return Iterator(*this, true);
    }
    
    void print(std::ostream& out){
        Iterator j = end();
        Iterator i = begin();
        
        out << *i;
        for (i++; i != j; i++){
            out << " " << *i;
        }
        
        out << std::endl;
    }
    
};

#endif /* MyFile_hpp */
