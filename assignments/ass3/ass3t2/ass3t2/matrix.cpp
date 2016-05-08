//
//  matrix.cpp
//  ass3t2
//
//  Created by Asjad Athick on 7/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include "matrix.h"
#include <cmath>


//---------matrix
template <class T>
matrix<T>::matrix(int r, int c){
    this->row = r;
    this->col = c;
    
    this->data = new T*[this->row];
    
    for (int i = 0; i < this->row; i++) {
        this->data[i] = new T[this->col];
    }
}

template <class T>
matrix<T>::~matrix(){
    if (data != NULL) {
        delete [] data;
    }
    row = 0;
    col = 0;
}

template <class T>
matrix<T> matrix<T>::operator+(const matrix<T>& value){
    if ((this->row != value.row) && (this->col != value.col)) {
        throw "Matrices need to be of the same size for addition.";
    }
    
    matrix<T> returnVal(this->row, this->col);
    
    for (int i = 0; i < returnVal.row; i++) {
        for (int j = 0; j < returnVal.col; j++) {
            returnVal.data[i][j] = this->data[i][j] + value.data[i][j];
        }
    }
    
    return returnVal;
}

template <class T>
matrix<T> matrix<T>::operator-(const matrix<T>& value){
    if ((this->row != value.row) && (this->col != value.col)) {
        throw "Matrices need to be of the same size for subtraction.";
    }
    
    matrix<T> returnVal(this->row, this->col);
    
    for (int i = 0; i < returnVal.row; i++) {
        for (int j = 0; j < returnVal.col; j++) {
            returnVal.data[i][j] = this->data[i][j] - value.data[i][j];
        }
    }
    
    return returnVal;
}

template <class T>
matrix<T> matrix<T>::operator*(const matrix<T>& value){
    if (this->col != value.row){
        throw "Row of Matrix A must equal Col of Matrix B for Multiplication.";
    }
    
    matrix<T> returnValue(this->row, value.col);
    
    for (int i = 0; i<this->row; i++) {
        for (int j = 0; j < value.col; j++) {
            returnValue.data[i][j] = 0;
            for (int k = 0; k < this->col; k++) {
                returnValue.data[i][j] += this->data[i][k] * value.data[k][j];
            }
        }
    }
    
    return returnValue;
}

//---------complexn

complexn::OutputState complexn::outstate = mcplx;

complexn::complexn(){
    this->realVal = 0;
    this->imgVal = 0;
}

complexn::complexn(float real, float img){
    this->realVal = real;
    this->imgVal = img;
}

std::ostream& operator<<(std::ostream& out, const complexn& instance){
    
    if (instance.outstate == complexn::mcplx) {
        out << "(" << instance.realVal << ", " << instance.imgVal << ")" << std::endl;
    }
    
    if (instance.outstate == complexn::mreal) {
        out << instance.realVal << std::endl;
    }
    
    if (instance.outstate == complexn::mimg) {
        out << instance.imgVal << std::endl;
    }
    
    if (instance.outstate == complexn::mmag) {
        double mag = (instance.realVal * instance.realVal) + (instance.imgVal * instance.imgVal);
        mag = sqrt(mag);
        
        out << mag << std::endl;
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, complexn& instance){
    
    in >> instance.realVal;
    in >> instance.imgVal;
    
    return in;
}

complexn operator+(const complexn& v1, const complexn& v2){
    
    complexn result((v1.realVal + v2.realVal), (v1.imgVal + v2.imgVal));
    
    return result;
}

complexn operator-(const complexn& v1, const complexn& v2){
    
    complexn result((v1.realVal - v2.realVal), (v1.imgVal - v2.imgVal));
    
    return result;
}

complexn operator*(const complexn& v1, const complexn& v2){
    
    complexn result(((v1.realVal * v2.realVal)) - ((v1.imgVal * v2.imgVal)), (v1.imgVal * v2.realVal) + (v1.realVal * v2.imgVal));
    
    return result;
}

std::ostream& complexn::cplx(std::ostream& s){
    outstate = mcplx;
    return s;
}

std::ostream& complexn::real(std::ostream& s){
    outstate = mreal;
    return s;
}

std::ostream& complexn::img(std::ostream& s){
    outstate = mimg;
    return s;
}

std::ostream& complexn::magnitude(std::ostream& s){
    outstate = mmag;
    return s;
}

