//
//  GasBill.hpp
//  ass2task2
//
//  mama158
//  Created by Asjad Athick on 6/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef GasBill_h
#define GasBill_h

#include "Bill.h"
#include <iostream>

class GasBill: public Bill{
private:
    double previousReading;
    double currentReading;
public:
    static float heatingValue;
    static float pressureFactor;
    static float rate;
    static float supplyCharge;
    
    GasBill();
    void calculateBillAmount();
    char getBillType() const;
    static void setNewRates();
    void printBill(std::ostream&);
    void loadBill(std::istream&);
    
    friend std::ostream& operator<<(std::ostream&, const GasBill&);
    friend std::istream& operator>>(std::istream&, GasBill&);
};

#endif /* GasBill_h */
