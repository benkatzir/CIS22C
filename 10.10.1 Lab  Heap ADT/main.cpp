/*
  Heaps - ADT

  This program will read data about overbooked customers,
  find their priority and serial numbers, build a heap, then display
  customers in priority sequence
 
  Written By: A. Student
  Changed By: Ben Katzir
  IDE: VS Code
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include "Customer.h"
#include "Heap.h"

using namespace std;

/* Write your code here */ 

int main()
{
    string inputFileName;
    cout << "Input file name: ";
    getline(cin, inputFileName);
    cout << endl;

    ifstream inputFile(inputFileName);
    if (!inputFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    Heap<Customer> heap(32); // Assuming the initial heap size is 32
    int seq = 0;
    char action;
    int years, mileage;
    string name;
    int servedCount = 0;

    while (inputFile >> action)
    {
        if (action == 'A')
        {
            inputFile >> years >> mileage;
            inputFile.ignore(); // Ignore the space before the name
            getline(inputFile, name);
            seq++;
            Customer cust(years, mileage, seq, name);
            heap.insertHeap(cust, compareMin);
        }
        else if (action == 'S')
        {
            Customer servedCustomer;
            if (heap.deleteHeap(servedCustomer, compareMin))
            {
                cout << servedCustomer << endl;
                servedCount++;
            }
            else
            {
                cout << "No customers to serve!" << endl;
            }
        }
    }

    inputFile.close();

    cout << "Served overbooked customers: " << servedCount << endl << endl;

    int rejectedCount = 0;
    while (!heap.isEmpty())
    {
        Customer remainingCustomer;
        heap.deleteHeap(remainingCustomer, compareMin);
        cout << remainingCustomer << endl;
        rejectedCount++;
    }

    cout << "Rejected overbooked customers: " << rejectedCount << endl;

    return 0;
}

/* Write your code here */ 

