// Car.h

//  Created by Emmanuel Amoh on 9/23/2020.
//  Copyright © 2020 Emmanuel Amoh. All rights reserved.

#ifndef program_hpp
#define program_hpp

#include <iostream>
#include <string>
#include "Node.hpp"
#include "UnorderedCarList.hpp"
#include "UnorderedReservationList.hpp"
#include "Car.h"
#include "Reservation.h"

class Program {
private:
    UnorderedCarList carList;
    UnorderedReservationList resList;

public:
    void RunProgram() {
        std::cout << "\n\nWelcome to the XYZ Car Rental company!\n";
        std::cout << "Here, we allow our customers to rent out our fine vehicles for an exchange of a payment, which is dependent on\n";
        std::cout << "how long our customers rent our vehicles for!\n";
        std::cout << "\nAs an employee of our company, you have access to our inventory and can update the information we have at any time.\n";
        std::cout << "Below is a menu where you can select what actions you would like to perform today at XYZ Car Rentals\n";


        while (true) {

            std::cout << "\nMenu:\n";
            std::cout << "1. List all cars\n";
            std::cout << "2. Add car to inventory\n";
            std::cout << "3. Remove car from inventory\n";
            std::cout << "4. List all reservations\n";
            std::cout << "5. Add a reservation\n";
            std::cout << "6. Cancel Reservation\n";
            std::cout << "7. Exit\n";

            int userInput;
            std::cout << "> ";
            std::cin >> userInput;

            while (userInput < 1 && userInput > 7) {
                std::cout << "\n\nYou're input is invalid. Here is the menu. Select one of these options by number:";
                std::cout << "Menu:\n";
                std::cout << "1. List all cars\n";
                std::cout << "2. Add car to inventory\n";
                std::cout << "3. Remove car from inventory\n";
                std::cout << "4. List all reservations\n";
                std::cout << "5. Add a reservation\n";
                std::cout << "6. Cancel Reservation\n";
                std::cout << "7. Exit\n";
                std::cout << "> ";
                std::cin >> userInput;
            }

            if (userInput == 1) {
                std::cout << carList << std::endl;

            } else if (userInput == 2) {
                Car temp;
                // runs a method that prompts user for data
                temp.AddCar(temp);
                // adds cars to car list
                carList.AddCar(temp);
                std::cout << "Car Successfully Added!\n";

            } else if (userInput == 3) {
                // to store platenumber
                std::string plateNum;

                std::cout << "Enter the car you would like to remove: ";
                std::cin >> plateNum;

                // delete item from car list
                carList.RemoveCar(plateNum);

                std::cout << "Car Successfully Removed!\n";

            } else if (userInput == 4) {

                std::cout << resList << std::endl;

            } else if (userInput == 5) {
                // stores user name and plate number to make reservation
                std::string nm;
                std::string plateNum;

                std::cout << "Please enter your name: ";
                std::cin >> nm;

                std::cout << "Here are all of the available options:\n";
                std::cout << carList << std::endl;

                // I tried using a for loop, but I got an error that I don't understand
                // error: invalid range expression of type 'UnorderedCarList *'; no viable 'begin' function available for (auto car: &carList) {
                // for (auto car: &carList) {
                //     std::cout << carList << std::endl;
                // }

                std::cout << "Enter the plate number of the car you want to reserve: ";
                std::cin >> plateNum;

                // Tries to access the car through the plate number
                // carList.GetCar(plateNum).GetPlateNumber() works. it returns the string of the plate number
                resList.AddReservation(Reservation(nm, carList.GetCar(plateNum).GetPlateNumber()));

                // check if plate number exists in car inventory
                while (!carList.CarExists(plateNum)) {
                    std::cout << "The plate number you have selected does not exist.\n";
                    std::cout << "Please select a plate number in the provided options:\n";
                    std::cout << carList << std::endl;
                    std::cout << "Enter plate number: ";
                    std::cin >> plateNum;
                }

                // sets car availablity to false
                carList.GetCar(plateNum).SetAvailable(false);

                std::cout << "Reservation Successfully Added!\n";


            } else if (userInput == 6) {
                std::string resName;
                std::cout << "Enter the reservation name you would like to remove: ";
                std::cin >> resName;

                // passes platenumber into method throught reservation class, and then assigns that car object to true for
                // availability
                carList.GetCar(resList.GetReservation(resName).GetVehicleRented()).SetAvailable(true);
                // Sets user input name to the name in class
                resList.GetReservation(resName).SetName(resName);
                // removes name
                resList.RemoveReservation(resList.GetReservation(resName).GetName());

                std::cout << "Reservation Successfully Removed!\n";


            } else {
                std::cout << "Thanks for using our XYZ Car Rental company software! Cya soon!\n";
                break;
            }

        }
















    }
};

#endif /* program_hpp */
