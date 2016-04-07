//
//  EVector.hpp
//  ass2
//
//  Created by Asjad Athick on 3/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef EVector_h
#define EVector_h

#include <iostream>
#include <istream>
#include <ostream>


class EVector{
private:
    double *array;
    int dimension;
public:
    EVector();
    EVector(int,const char*);
    ~EVector();
    friend std::istream& operator>>(std::istream&, EVector&);
    friend std::ostream& operator<<(std::ostream&, const EVector&);
    EVector& operator=(const EVector&);
    EVector operator+(const EVector&) const;
    EVector operator-(const EVector&);
    double operator*(const EVector&);
    EVector operator*(const double);
    friend EVector operator*(const double, const EVector&);
    EVector operator/(const double);
    //extra comment
};

#endif /* EVector_h */
