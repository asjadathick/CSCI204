//
//  TelephoneBill.hpp
//  ass2task2
//
//  Created by Asjad Athick on 6/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef TelephoneBill_h
#define TelephoneBill_h

#include <iostream>
#include "Bill.h"

class TelephoneBill: public Bill{
private:
    double numberOfLocalCalls;
    double internationalCallAmount;
public:
    static float localCallRate;
    static float lineRental;
    static float internetConnection;
    
    TelephoneBill();
    void calculateBillAmount();
    char getBillType() const;
    
    friend std::ostream& operator<<(std::ostream&, const TelephoneBill&);
    friend std::istream& operator>>(std::istream&, TelephoneBill&);
};

#endif /* TelephoneBill_h */
