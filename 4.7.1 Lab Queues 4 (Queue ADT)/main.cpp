/*
 Written by: Ben Katzir
 =================================
Project: Queue ADT
Parallel queues. Create two queues:
 - the first queue contains the names of the students enrolled in CIS 22C
 - the second queue contains the number of units each student is taking this quarter
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include "QueueADT.h"

using namespace std;

vector<double> stringToDoubleArray(const string& input) {
    vector<double> numbers;
    istringstream iss(input);
    double num;

    // Read each double number from the stringstream and push it into the vector
    while (iss >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

int main() {

    // Create the first queue (strings)
    Queue<string> que;
    string item;

    // Write a loop to enter an unknown number of names, one per line. 
    while (true) {
        getline(cin, item);
        // The loop stops when you enter #.
        if (item == "#")
            break;
        que.push(item);
    }

    // Create the second queue (doubles)
    Queue<double> que2;
    string item2;

    // Test the getLength function: - display the number of elements in the second and first queue
    int que1Length = que.getLength();
    if (que1Length == 0) {
        cout << "Empty Queues!" << endl;
        exit(1);
    } else {
        int que2Length = que2.getLength();
        cout << que1Length << " " << que2Length << endl; // que2 length should be 0!
    }


    // Write another loop to enter the number of units (double) into a parallel queue. 
    int que2Inputs; // keep track of how many inputs for que2
    while (true) {
        if (que1Length == que2Inputs)
            break;
        getline(cin, item2);
        regex pattern("\\d \\d"); // are all number inputs written on one line (identify spaces between the numbers)
        if (regex_search(item2, pattern)) {
            vector<double> numbers = stringToDoubleArray(item2);

            // Output the array of double numbers
            for (double num : numbers) {
                que2.push(num);
            }
            break;
        }//*/
        ++que2Inputs;
        que2.push(stod(item2));
    }

    string que1Peek = que.peek();
    string que1Rear = que.peekRear();
    double que2Peek = que2.peek();
    double que2Rear = que2.peekRear();

    // Display the two queues in parallel.
    while (!que.isEmpty() || !que2.isEmpty()) {
        cout << que.pop() << " " << que2.pop() << endl;
    }

    // On the next line display the front elements in the first queue and second que. 
    cout << "Front of the queues: " << que1Peek << " " << que2Peek << endl;

    // On the next line display the rear elements in the first queue and second que. 
    cout << "Rear of the queues: " << que1Rear << " " << que2Rear << endl;
    
    return 0;
}
