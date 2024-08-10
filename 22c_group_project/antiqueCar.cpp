
/*
Description:
The antiqueCar class encapsulates the properties and behaviors of an antique car object within the antique car management system. It provides constructors for initializing car attributes, comparison operators for car ID comparisons, and display functions for formatted output. The class supports operations such as checking if one car is older than another based on their manufacturing year, and overloading comparison operators for car ID comparisons. Additionally, it offers display functions (iDisplay, hDisplay, vDisplay) for showing car details in indented, horizontal, and vertical formats respectively, aiding in visualizing car data within the application.
*/

#include "antiqueCar.h"
#include <iostream>
#include <string>

// **************************************************
// Constructor
// **************************************************
antiqueCar::antiqueCar()
{
    carID = -1;
    make = "";
    model = "";
    year = -1;
    condition = "";
}

// **************************************************
// Overloaded Constructor
// **************************************************
antiqueCar::antiqueCar(int id) {
    carID = id;
    make = "";
    model = "";
    year = -1;
    condition = "";
}

antiqueCar::antiqueCar(int id, string mk, string mdl, int yr, string cnd)
{
    carID = id;
    make = mk;
    model = mdl;
    year = yr;
    condition = cnd;
}

bool antiqueCar::isOlder(const antiqueCar& otherCar) const {
    return (year < otherCar.getYear());
}

// **************************************************
// Overloaded Opperators
// **************************************************
bool antiqueCar::operator > (const antiqueCar& otherCar) const {
    return (carID > otherCar.getCarID());
}

bool antiqueCar::operator < (const antiqueCar& otherCar) const {
    return (carID < otherCar.getCarID());
}

bool antiqueCar::operator == (const antiqueCar& otherCar) const {
    //return (carID == otherCar.getCarID());
    return carID == otherCar.getCarID();
}

ostream& operator<<(ostream& os, const antiqueCar& car) {
    os << "CarID: " << car.carID << ", Make: " << car.make
       << ", Model: " << car.model << ", Year: " << car.year
       << ", Condition: " << car.condition;
    return os;
}


// ***********************************************************
// iDisplay
// on one line, including the level number and 
// ".." for each indentation level
// ***********************************************************
void iDisplay(const antiqueCar &item, int level)
{
    for (int i = 1; i < level; i++)
        cout << "..";
    cout << level << "). " << item.carID << endl;
}

// ***********************************************************
// hDisplay
// Displays code, state, and year data members of a Park object 
// on one line (horizontal display)
// ***********************************************************
void hDisplay(const antiqueCar &item)
{
    cout << item.carID  << "  ";
    cout << item.make << "  ";
    cout << item.model  << "  ";
    cout << item.year  << "  ";
    cout << item.condition  << "  ";
    cout << endl;
}

// ***********************************************************
// vDisplay
// Displays ID, make, model, year, and condition of the car
// on multiple lines (vertical display).
// ***********************************************************
void vDisplay(const antiqueCar& item)
{
    cout << "---------------------------" << std::endl;
    cout << "   Car ID: " << item.getCarID() << std::endl;
    cout << "   Make: " << item.getMake() << std::endl;
    cout << "   Model: " << item.getModel() << std::endl;
    cout << "   Year: " << item.getYear() << std::endl;
    cout << "   Condition: " << item.getCondition() << std::endl;
    cout << "---------------------------" << std::endl;
}

