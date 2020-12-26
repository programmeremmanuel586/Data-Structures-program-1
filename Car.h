// Car.h

//  Created by Emmanuel Amoh on 9/23/2020.
//  Copyright © 2020 Emmanuel Amoh. All rights reserved.

#ifndef Car_h
#define Car_h

#include <iostream>
#include <string>
#include "enum.hpp"

class Car {
private:
    std::string plateNumber;    // this is the key
    std::string make;
    std::string vType;          // vehicle enum type
    double pricePerDay;
    bool isAvailable = true;

public:
    Car(std::string plateNum, std::string m, std::string vt, double ppd, bool isAvail):
        plateNumber{plateNum},
        make{m},
        vType{vt},
        pricePerDay{ppd},
        isAvailable{isAvail}
    {}

    Car() {}

    void SetAvailable(bool available);
    bool GetAvailablity();
    std::string GetPlateNumber() const;

    void AddCar(Car &c);
    void vehicleTypeToString(Car &c, vehicleType vt);

    friend std::ostream& operator<<(std::ostream& os, const Car& c);
};

#endif /* Car_h */
