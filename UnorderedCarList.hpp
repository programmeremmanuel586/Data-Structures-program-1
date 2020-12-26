//
//  UList.hpp
//  UList
//
//  Created by Emmanuel Amoh on 9/23/2020.
//  Copyright © 2020 Eugene Lymar. All rights reserved.
//

#ifndef UnorderedCarList_hpp
#define UnorderedCarList_hpp

#define MAX_ELEMS 100

#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.hpp"
#include "Car.h"

using namespace std;

class UnorderedCarList {
private:
	int length{};
	Node<Car>* currentPos{};
	Node<Car>* head{};		// intialization of a list

public:

	// nullptr means that the beginning of the list points to nothing bc the list is empty
	// UnorderedLinkedList(): length{0}, currentPos{nullptr}, head{nullptr} {}
    UnorderedCarList() {}

    ~UnorderedCarList(){
    	MakeEmpty();		// deletes each node in the list
    }

    // Checks if plate number exist in carlist
    bool CarExists(std::string plateNum) {
        Node<Car>* temp = head;
    	while(temp != nullptr){		// while not at the end of the list
    		if(temp->data.GetPlateNumber() == plateNum) {
                return true;		// if the value of the node equals the item
    		}
    		temp = temp->next;		// move to next node in list
    	}
    	throw "not found";
        return false;
    }

    void MakeEmpty(){
    	Node<Car>* temp = nullptr;
    	while(head != nullptr){			// while list is not empty
    		temp = head;				// assign temp to current head node
    		head = head->next;			// assign head to node after current head node
    		delete temp;				// delete current head node
    	}
    	length = 0;						// set list length to zero
    }

    // PutItem
    void AddCar(Car item){
    	Node<Car>* temp = new Node<Car>;			// create new node for new item
    	temp->data = item;				// assigning node to new item
    	temp->next = head;				// assigning next node to head node
    	head = temp;					// head points to temp node
    	length++;						// increment 1 to length
    }


    // here is where the key is used instead of the item
    // GetItem
    Car GetCar(std::string item){
    	Node<Car>* temp = head;
    	while(temp != nullptr){		// while not at the end of the list
    		if(temp->data.GetPlateNumber() == item) {
    			return temp->data;
    		}
    		temp = temp->next;		// move to next node in list
    	}
    	throw "not found";
    }

    // use platenumber as a key.
    // DeleteItem
    void RemoveCar(std::string item){

        // we have a list of available cars
        // to delete a car means that we are removing it from our roster
        // if the user has rented it (SetAvailable = false), then don't remove from roster yet.

        // Check if car is available in our inventory
        // if (!item.GetAvailablity()) {
        //     std::cout << "Sorry, this vehicle is not in our inventory right now. Try again later.\n";
        //     std::exit(EXIT_SUCCESS);
        // }

        // Remove a vehicle from the list of available cars.
        // If the car is not available (a user has rented it) return an error message and don't remove the vehicle



    	// Empty case
    	if(head == nullptr)		// if head equals nullptr, then list is empty
    		return;

    	Node<Car>* temp;
    	// Deleting head
    	if(head->data.GetPlateNumber() == item) {	// if value stored at head node is equal to item
    		temp = head->next;	// assign a temporary node to the node after the head node
    		delete head;		// delete the head node item
    		head = temp;		// reassign head to temp node pointed at item after the deleted node
    		length--;			// substract the length by 1
    		return;
    	}

    	// Deleting further in the list
    	temp = head;
    	while(temp->next != nullptr){				                                   // while item after current node isn't equal to nullptr
    		if(temp->next->data.GetPlateNumber() == item) {		   // if the node after the current node is equal to item
    			Node<Car>* temp2 = temp->next;			                               // create a temporary variable to store the node after the current one
    			temp->next = temp->next->next;		                                   // node after current node now points to the node after the node after the current node
    			delete temp2;						                                   // the node after the current node is deleted
    			length--;							                                   // list length is substracted by one
    			return;								                                   // exit function (doesn't run line 64)
    		}
    		temp = temp->next;						                                   // moves to next node (like length++)
    	}
    }


    void ResetList(){
    	currentPos = head;							// sets the node pointing to the items in the list to the very beginning
    }

    Car GetNextItem(){
    	if(currentPos == nullptr)					// if list is empty (which means there is nothing to check)
    		throw "Out of range";

    	Car data = currentPos->data;				    // creates and assigns new item
    	currentPos = currentPos->next;				// assigns next node to current position
    	return data;								// returns data (which is the item)
    }

    int GetLength(){
    	return length;
    }
};

std::ostream& operator<<(std::ostream& os, UnorderedCarList& o){
	o.ResetList();
    os << "Cars: [";
	for(int i = 0; i < o.GetLength(); ++i){
		os << "(" << o.GetNextItem() << ")" << std::endl;
		if (i < o.GetLength() - 1) os << ", ";
	}
	os << "]";
	return os;
}

#endif /* UnorderedCarList_hpp */
