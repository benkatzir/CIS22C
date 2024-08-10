/* *~*~*
  Specification file for the Customer class
  Written By: A. Student
  Changed by: Ben Katzir
  IDE: VS Code
  *~**/
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class  Customer; // Forward Declaration

// Function Prototypes for friend functions
/* Write your code here */
int compareMin(const Customer &c1, const Customer &c2);
int compareMax(const Customer &c1, const Customer &c2);
ostream &operator<<(ostream &out, const Customer &c);

class Customer
{
private:
    int year;
    int mileage;
    int seq;
	 string name;
	
public:
   /* Write your code here */
    Customer() : year(0), mileage(0), seq(0), name("") {}
    Customer(int year, int mileage, int seq, const string &name);

    int getYear() const { return year; }
    int getMileage() const { return mileage; }
    int getSeq() const { return seq; }
    string getName() const { return name; }

    friend int compareMin(const Customer &c1, const Customer &c2);
    friend int compareMax(const Customer &c1, const Customer &c2);
    friend ostream &operator<<(ostream &out, const Customer &c);   

};
#endif