// Specification file for the Student class
// Modified by: Ben Katzir
// IDE: Vs Code

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using std::string;

class Student; // Forward Declaration

// Function Prototypes for friend functions
int key_to_index(const Student &key, int size);

class Student
{
private:
    double gpa;
    string name;

public:
    Student() {name = ""; gpa = -1;}  // Constructor
    Student(string n, double g) {name = n; gpa = g;}  // Overloaded Constructor

    // Setters and getters
    void setName(string n) {name = n;}
    void setGpa(double g) {gpa = g;}
    string getName() const {return name;}
    double getGpa() const {return gpa;}

    // Overloaded operators
    bool operator==(const Student &rhs) const
    {
        return name == rhs.name;
    }

    // friend functions
    friend int key_to_index(const Student &key, int size);
};

#endif
