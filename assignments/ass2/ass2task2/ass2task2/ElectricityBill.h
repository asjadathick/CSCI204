//
//  ElectricityBill.hpp
//  ass2task2
//
//  Created by Asjad Athick on 5/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef ElectricityBill_h
#define ElectricityBill_h

#include "Bill.h"
#include <iostream>

class ElectricityBill : public Bill{
private:
    double previousReading;
    double currentReading;
public:
    static float rate1;
    static float rate1Threshold;
    static float rate2;
    static float supplyCharge;
    
    ElectricityBill();
    void calculateBillAmount();
    char getBillType() const;
    static void setNewRates();
    void printBill(std::ostream&);
    void loadBill(std::istream&);
    
    friend std::ostream& operator<<(std::ostream&, const ElectricityBill&);
    friend std::istream& operator>>(std::istream&, ElectricityBill&);
    
};

#endif /* ElectricityBill_h */
