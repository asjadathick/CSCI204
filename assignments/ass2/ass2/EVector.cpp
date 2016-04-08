//
//  EVector.cpp
//  ass2
//
//  mama158
//  Created by Asjad Athick on 3/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <sstream>
#include "EVector.h"
using namespace std;

EVector::EVector(){
    this->dimension = 0;
    this->array = NULL;
}

EVector::EVector(int dim, const char* value){
    this->dimension = dim;
    this->array = new double[this->dimension];
    
    string valstr = value;
    stringstream stream;
    stream << valstr;
    stream.flush();
    
    for (int i = 0; i<this->dimension; i++) {
        stream >> this->array[i];
        
    }
}

EVector::~EVector(){
    if (this->array != NULL) {
        delete [] this->array;
    }
}

istream& operator>>(istream& in, EVector& vec){
    char buffer[1024]; //max 1024 chars
    in.getline(buffer, 1023, '\n');
    
    int size = atoi(buffer);
    
    in.getline(buffer, 1023, '\n');
    
    EVector tmpVec(size, buffer);
    vec = tmpVec;
    return in;
}

ostream& operator<<(ostream& out, const EVector& vec){
    out.flush();
    out << vec.array[0];
    for (int i = 1; i<vec.dimension; i++) {
        out << ", " << vec.array[i];
    }
    return out;
}

EVector& EVector::operator=(const EVector& val){
    if (this->array != NULL) {
        delete [] this->array;
    }
    
    this->dimension = val.dimension;
    this->array = new double[this->dimension];
    
    for (int i = 0; i<this->dimension; i++) {
        this->array[i] = val.array[i];
    }
    
    return *this;
}

EVector EVector::operator+(const EVector& val) const{
    EVector result;
    result = val;
    
    //check dimensions
    if (this->dimension == 0 || val.dimension ==0 ) {
        cout << "Dimension zero, no tuple memory has been allocated" << endl;
        return result;
    }
    if (this->dimension != val.dimension) {
        //return error
        cout << "Two Euclidean vectors should be in the same Euclidean space" << endl;
        return result;
    }
    
    for (int i = 0; i<this->dimension; i++) {
        result.array[i] += this->array[i];
    }
    
    return result;
}

EVector EVector::operator-(const EVector& val){
    EVector result;
    result = *this;
    
    //check dimensions
    if (this->dimension == 0 || val.dimension ==0 ) {
        cout << "Dimension zero, no tuple memory has been allocated" << endl;
        return result;
    }
    if (this->dimension != val.dimension) {
        //return error
        cout << "Two Euclidean vectors should be in the same Euclidean space" << endl;
        return result;
    }

    
    for (int i = 0; i<this->dimension; i++) {
        result.array[i] -= val.array[i];
    }
    
    return result;
}

double EVector::operator*(const EVector& val){
    double result=0;
    
    //check dimensions
    if (this->dimension == 0 || val.dimension ==0 ) {
        cout << "Dimension zero, no tuple memory has been allocated" << endl;
        return result;
    }
    if (this->dimension != val.dimension) {
        //return error
        cout << "Two Euclidean vectors should be in the same Euclidean space" << endl;
        return result;
    }

    
    for (int i = 0; i<this->dimension; i++) {
        result += val.array[i] * this->array[i];
    }
    
    return result;
}

EVector EVector::operator*(const double val){
    EVector result;
    result = *this;
    
    for (int i = 0; i<this->dimension; i++) {
        result.array[i] *= val;
    }
    
    return result;
}

EVector operator*(const double num, const EVector& val){
    EVector result;
    result = val;
    
    for (int i = 0; i<val.dimension; i++) {
        result.array[i] *= num;
    }
    
    return result;
}

EVector EVector::operator/(const double val){
    EVector result;
    result = *this;
    
    for (int i = 0; i<this->dimension; i++) {
        result.array[i] /= val;
    }
    
    return result;
}



