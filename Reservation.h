// Car.h

//  Created by Emmanuel Amoh on 9/23/2020.
//  Copyright © 2020 Emmanuel Amoh. All rights reserved.

#ifndef Reservation_h
#define Reservation_h

#include <iostream>
#include <string>

class Reservation {
private:
    std::string name;   // this is the key
    std::string vehicleRented;  // plate of car thats key of Car class
public:
    Reservation(std::string n, std::string vehicle): name{n}, vehicleRented{vehicle} {}
    void SetName(std::string n);
    std::string GetName() const;
    std::string GetVehicleRented() const;

    friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
};

#endif /* Reservation.h */
