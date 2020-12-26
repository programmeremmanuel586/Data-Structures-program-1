// Reservation.cpp

//  Created by Emmanuel Amoh on 9/23/2020.
//  Copyright © 2020 Emmanuel Amoh. All rights reserved.

#include <iostream>
#include <string>
#include "Reservation.h"

void Reservation::SetName(std::string n) {
    name = n;
}

std::string Reservation::GetName() const {
    return name;
}

std::string Reservation::GetVehicleRented() const {
    return vehicleRented;
}

std::ostream& operator<<(std::ostream& os, const Reservation& res){
	os << "Reservation: [" << res.GetName() << "]";
	return os;
}
