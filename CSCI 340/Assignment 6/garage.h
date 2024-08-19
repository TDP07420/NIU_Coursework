#ifndef H_GARAGE
#define H_GARAGE

/* 	Thomas Dela Pena
	z120111
	CSCI 340 Section 1

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include "car.h"

#include <string>
#include <deque>
#include <stack>
#include <cstdio>
#include <algorithm>

class garage
{
public:
    garage(size_t limit = 10) : parking_lot_limit(limit) {}

    /*
    *   Announces a car's arrival.
    * 
    *   @param license The license of the car that has arrived.
    * 
    *   @note if garage is not full, insert car into parking_lot deque
    *         else print message to say garage is full.
    */ 
    void arrival(const std::string& license)
    {
        car aCar(next_car_id, license);     //create a car object
                
        std::cout << aCar;

        if (parking_lot.size() == parking_lot_limit)    
        {
            std::cout << "But the garage is full!\n";   //print if garage is full
        }
        else
        {
            parking_lot.push_front(aCar);               //insert if garage is not full
        }

        next_car_id++;
    }
    /*
    *   Announces a car's departure
    * 
    *   @param license The license of the car that has departed.
    * 
    *   @note must move cars in front if car departuring is not front most
    */ 
    /*void departure(const std::string& license)
    {
        std::stack<car> Scar;   //declare stack

        auto it = std::find(parking_lot.begin(), parking_lot.end(), 
                  parking_lot.get_license(aCar) == license);

        if(it == parking_lot.end())
        {
            std::cout << "But garage is full";
        }
        
    }*/

private:
    int next_car_id = { 1 };
    std::deque<car> parking_lot;
    size_t parking_lot_limit;
};


#endif