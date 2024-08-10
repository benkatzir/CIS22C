/* *~*~*
Implementation file for the Customer class
Written By: A. Student
Changed by: Ben Katzir
IDE: VS Code
*~**/
#include <iostream>
#include <string> 
#include "Customer.h"

using namespace std;

/* Write your code here */
Customer::Customer(int year, int mileage, int seq, const string &name)
    : year(year), mileage(mileage), seq(seq), name(name)
{
}

int calculatePriority(const Customer &c)
{
    return c.getMileage() / 1000 + c.getYear() - c.getSeq();
}

int calculateSerial(const Customer &c)
{
    return calculatePriority(c) * 100 + (100 - c.getSeq());
}

int compareMin(const Customer &c1, const Customer &c2)
{
    return calculateSerial(c1) > calculateSerial(c2);
}

int compareMax(const Customer &c1, const Customer &c2)
{
    return calculateSerial(c1) < calculateSerial(c2);
}

ostream &operator<<(ostream &out, const Customer &c)
{
    out << c.getYear() << " " << c.getMileage() << " (" << calculateSerial(c) << ") [" << c.getName() << "]";
    return out;
}
