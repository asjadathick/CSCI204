//
//  matrix.hpp
//  ass3t2
//
//  Created by Asjad Athick on 7/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <iostream>
enum OutputState {mcplx, mreal, mimg, mmag};

//global variables for use by manipulators
bool infoState = false;
OutputState outstate = mcplx;

//manipulators - matrix
std::ostream& info(std::ostream&);
std::ostream& noinfo(std::ostream&);

//manipulators - complexn
std::ostream& cplx(std::ostream&);
std::ostream& real(std::ostream&);
std::ostream& img(std::ostream&);
std::ostream& magnitude(std::ostream&);

class complexn;

template <class T>
class matrix {
    T **data;
    int row, col;
public:
    matrix(int r, int c);
    ~matrix();
    matrix<T> operator+(const matrix<T>&);
    matrix<T> operator-(const matrix<T>&);
    matrix<T> operator*(const matrix<T>&);

    //friend members
    friend std::ostream& operator<<(std::ostream& out, const matrix<T>& inp){
        
        if (infoState) {
            out << inp.row << "x" << inp.col << " matrix\n";
        }
        
        for (int i = 0; i < inp.row; i++) {
            for (int j = 0; j < inp.col; j++) {
                out << inp.data[i][j] << '\t';
            }
            out << std::endl;
        }
        out << std::endl;
        return out;
    }
    
    friend std::istream& operator>>(std::istream& in, matrix<T>& instance){
        //init
        for (int i = 0; i < instance.row; i++) {
            for (int j = 0; j < instance.col; j++) {
                in >> instance.data[i][j];
            }
        }
        return in;
    }
};


class complexn{
    float realVal, imgVal;
    
public:
    complexn();
    complexn(float real, float img);
    complexn& operator=(int);
    
    friend std::ostream& operator<<(std::ostream&, const complexn&);
    friend std::istream& operator>>(std::istream&, complexn&);
    friend complexn operator+(const complexn&, const complexn&);
    friend complexn operator-(const complexn&, const complexn&);
    friend complexn operator*(const complexn&, const complexn&);
    
};

#endif /* matrix_hpp */
