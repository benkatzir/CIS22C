// Specification file for the Student List class
// Written by: A. Student
// Reviewed by: Ben Katzir
// IDE: VS Code

#ifndef STUDENT_H
#define STUDENT_H

#include <string> // Include necessary header for std::string

class Student
{
private:
    double gpa;
    std::string name;

public:
    // Constructors
    Student() : gpa(0.0), name("") {} // Default constructor
    Student(double initialGPA, const std::string& initialName) : gpa(initialGPA), name(initialName) {} // Overloaded constructor

    // Destructor
    ~Student() {}

    // Setter and getter for GPA
    void setGPA(double newGPA) { gpa = newGPA; }
    double getGPA() const { return gpa; }

    // Setter and getter for name
    void setName(const std::string& newName) { name = newName; }
    const std::string& getName() const { return name; }
};

#endif
