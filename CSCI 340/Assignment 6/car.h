#ifndef H_CAR
#define H_CAR

/* 	Thomas Dela Pena
	z120111
	CSCI 340 Section 1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include <iostream>
#include <string>

class car
{
public:
    car(int id, const std::string &license) : id(id), license(license) {}

    /*
    *   Call this to increment the number of times the car has been moved.
    */ 
    void move()
    {
        num_moves++;
    }

    /*
    *   @return the number of times that the car has been moved.
    */ 
    int get_num_moves() const
    {
        return num_moves;
    }
	
    /*
    *   @return A reference to the license for this car.
    */ 
    const std::string& get_license() const
    {
        return license;
    }

    /**
    * Overload the << so this can print itself as:
    *    Car X with license plate "Y"
    ******************************************************************/
    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs)
    {
        lhs << "Car " << rhs.id << " with license plate " << rhs.get_license()
            << " has arrived." << std::endl;

        return lhs;
    }

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};

#endif