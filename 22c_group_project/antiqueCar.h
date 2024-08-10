/*
Description:
Defines the antiqueCar class with attributes for car ID, year, make, model, and condition. Provides constructors, setters, getters, and comparison operators. Includes friend functions for formatted output and display.
*/

#ifndef ANTIQUECAR_H
#define ANTIQUECAR_H

#include <iostream>
#include <string>

using namespace std;

class antiqueCar {
private:
    int carID;
    int year;
    string make;
    string model;
    string condition;

public:
    // constructors
    antiqueCar();
    antiqueCar(int);
    antiqueCar(int, string, string, int, string);

    // setters
    void setCarID(int num) { carID = num; }
    void setYear(int date) { year = date; }
    void setMake(string company) { make = company; }
    void setModel(string type) { model = type; }
    void setCondition(string status) { condition = status; }

    // getters
    int getCarID() const { return carID; }
    int getYear() const { return year; }
    string getMake() const { return make; }
    string getModel() const { return model; }
    string getCondition() const { return condition; }

    // overloaded operators
    bool isOlder(const antiqueCar& otherCar) const;
    bool operator > (const antiqueCar& otherCar) const;
	bool operator < (const antiqueCar& otherCar) const;
    bool operator == (const antiqueCar& otherCar) const;

    // friend function to output car information
    friend ostream& operator<<(ostream& os, const antiqueCar& car);

    // friend function to display indented list
    friend void hDisplay(const antiqueCar &);
    friend void iDisplay(const antiqueCar &item, int level);

};

// Function Prototypes for friend functions
void iDisplay(const antiqueCar &, int);
void hDisplay(const antiqueCar &);
void vDisplay(const antiqueCar&);

#endif 
