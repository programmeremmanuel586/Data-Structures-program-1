// Car.cpp

//  Created by Emmanuel Amoh on 9/23/2020.
//  Copyright © 2020 Emmanuel Amoh. All rights reserved.

#include <iostream>
#include <string>
#include "Car.h"

void Car::SetAvailable(bool available) {
    isAvailable = available;
}

bool Car::GetAvailablity() {
    return isAvailable;
}

std::string Car::GetPlateNumber() const {
    return plateNumber;
}

// Prompt for all the information for a vehicle (implemented in Car class)
// Create the vehicle and add it to the list of available vehicles (implemented in Program class)

void Car::AddCar(Car &c) {
    int userInput;
    std::cout << "Enter the vehicle's plate number: ";
    std::cin >> c.plateNumber;

    std::cout << "Enter the vehicle's make: ";
    std::cin >> c.make;

    std::cout << "Pick a vehicle type:\n1) Sedan\n2) SUV\n3) Exotic\n> ";
    std::cin >> userInput;
    while (userInput != 1 && userInput != 2 && userInput != 3) {
        std::cout << "You've entered an invalid input.\n";
        std::cout << "Pick a vehicle type:\n1) Sedan\n2) SUV\n3)Exotic\n> ";
        std::cin >> userInput;
    }

    // Convert user input to enum type
    vehicleType type = static_cast<vehicleType>(userInput - 1);
    vehicleTypeToString(c, type);

    std::cout << "Enter the price per day: ";
    std::cin >> pricePerDay;
    while (pricePerDay <= 0) {
        std::cout << "You've enter an invalid input.\n";
        std::cout << "Enter the price per day: ";
        std::cin >> c.pricePerDay;
    }
}


void Car::vehicleTypeToString(Car &c, vehicleType vt) {
    switch (vt) {
        case vehicleType::SEDAN:
            c.vType = "Sedan";
            break;
        case vehicleType::SUV:
            c.vType = "SUV";
            break;
        case vehicleType::EXOTIC:
            c.vType = "Exotic";
            break;
    }
}

std::ostream& operator<<(std::ostream& os, const Car& c){
	os << "Vehicle Details: [Plate Number: " << c.plateNumber << " | Make: " << c.make << " | Vehicle Type: " << c.vType << " | Price Per Day: $" << c.pricePerDay << "]";
	return os;
}
