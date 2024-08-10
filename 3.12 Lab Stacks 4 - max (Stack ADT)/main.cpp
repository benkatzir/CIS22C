/* 
Written by: Ben Katzir
=============================
CIS 22C
Project: Stack ADT
*/
#include "StackADT.h"
#include <sstream> // For stringstream
#include <fstream>
#include <iostream>
#include <string>
#include <fstream> // For file operations
#include <cstdlib>
#include <stdexcept>

using namespace std;

/*
This function displays the project's title
*/
void printInfo()
{
    cout << " ~*~ Project: Stack ADT ~*~ " << endl;
}

// A function to process the input file
void processNumbers(Stack<int> &s, Stack<int>& s2, ifstream& inputFile, string filename) {
    int num;
    cout << "Input File: " << filename << endl;
    while (inputFile >> num) {
        if (num == 1) {
            if (s.isEmpty()) {
                cout << "Top: Empty" << endl;
            } else {
                cout << "Top: " << s.peek() << endl;
                cout << "Max: " << s2.peek() << endl;
            }
        } else if (num < 0) {
            if (s.isEmpty()) {
                cout << "Pop: Empty" << endl;
            } else {
                int poppedValue = s.pop();
                cout << "Pop: " << poppedValue << endl;
                // if the popped value is equal to the current max of the stack remove it from s2 (the max stack)
                if (poppedValue == s2.peek()) {
                    s2.pop();
                }
                if (!s.isEmpty()) {
                    cout << "Max: " << s2.peek() << endl;
                }
            }
        } else if (num == 0) {
            cout << "Count: " << s.getLength() << endl;
        } else {
            s.push(num);
            // if the max stack is empty push the peek of the stack to max stack
            if (s2.isEmpty()) {
                s2.push(s.peek());
            } 
            // if the new value pushed to the stack is a new max value (greater than the peek() (and only value) in s2)
            else if (s.peek() > s2.peek()) {
                s2.push(s.peek());
            }
        }
    }
}

// A function to print the stack
void printStack(Stack<int> & s) {
    cout << "Stack: ";
    // if the stack is empty just print empty
    if (s.isEmpty()) {
         cout << "Empty" << endl; 
    } else {
        cout << s.pop();
        // if stack is not empty pop out all values and print them
        while (!s.isEmpty()) {
            cout << ", " << s.pop();
        }
        cout << "." << endl;
    }
}

int main()
{
    printInfo();

    cout << "Enter input file name: " << endl;
    string filename;
    getline(cin, filename); // assume valid
    try {
        ifstream inputFile(filename); // Open input file
        if (!inputFile) {
            cout << "There was an error opening \"" << filename << "\". Exiting." << endl;
            return 1; // Return with error code
        }
        cout << endl;

        Stack<int> s; // Declare stack here
        Stack<int> s2; // Declare stack to store maxvalue
            
        processNumbers(s, s2, inputFile, filename); // Call processNumbers()

        printStack(s); // Call printStack()

        inputFile.close(); // Close input file

    } catch (const runtime_error& e) {
        cout << "There was an error opening \"" << filename << "\". Exiting." << endl;
    }

    

    return 0;
}
