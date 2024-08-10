/*
Description:
This file manages antique car data using Binary Search Tree (BST) and Hash Table data structures. It handles file operations, user input, and various functionalities like adding, deleting, and searching cars. Additional features include undoing deletions, displaying data structures, and saving to files. Integrates modules for comprehensive data management. 
*/

#include "BinarySearchTree.h"
#include "HashTable.h"
// #include "testerhash.h" // debug
#include "antiqueCar.h"
#include "StackADT.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
using namespace std;

/* NOTE:
    Input Data File: antique_cars.txt
    Second Input Data File (for "INS - insert data from file" menu option): second_antique_cars.txt
    Demonstration Test Plan: demonstration_test_plan.pdf
    Output (based on the demonstration test plan - NOT THE OUTPUT FILE): output_example.txt
    Output File: output.txt

*/

/*
PROGRAMMER - BEN KATZIR
    Contribution: 
    I initialized the project by creating the original replit
    with our boiler plate main code. I created our first versions
    of the following functions which only worked with BST:
        loadCarsFromFile
        displayMenu
        addNewCar
        deleteCar
        inOrderTraversal
        displayIndentedTree

    Later I worked with the rest of the team to help integrate 
    these with the rest of the units as well as helping debug searchManager
    before our presentation on Thursday

    When we reached our mostly final version of our project I went over all the requirements
    and made sure to redesign the menu adding options F, DIS and H.

    After recieving feedback on Thursday I made sure to add menu options INS to insert
    from file, modify addNewCar to not allow duplicate items, and to automatically 
    save to file when exiting the program
*/

// Function prototypes
void loadCarsFromFile(BinarySearchTree<antiqueCar>& tree, HashTable<antiqueCar>& hash, const string& filename);
void displayMenu();
void addNewCar(BinarySearchTree<antiqueCar>& tree, HashTable<antiqueCar>& hash);
void deleteCar(BinarySearchTree<antiqueCar>& tree, HashTable<antiqueCar>& hash, Stack<antiqueCar>& s);
void inOrderTraversal(const BinarySearchTree<antiqueCar>& tree);
void displayIndentedTree(const BinarySearchTree<antiqueCar>& tree);
void searchManager(HashTable<antiqueCar>& hash);
void displayManager(BinarySearchTree<antiqueCar>& tree);
void undoDelete(BinarySearchTree<antiqueCar>& tree, HashTable<antiqueCar>& hash, Stack<antiqueCar>& stack);
int hashSize(string file);
int countLines(string file);
int nextPrime(int num);
bool isPrime(int num);

int main() {
    BinarySearchTree<antiqueCar> carTree;
    int hashTableSize = 61;
    HashTable<antiqueCar> hash(hashTableSize);
    Stack<antiqueCar> undoStack;

    // Load cars from file
    loadCarsFromFile(carTree, hash, "antique_cars.txt");

    string choice;
    displayMenu();
    do {
        cin >> choice;
        cin.ignore(); // Ignore newline character

        // Convert to lowercase
        transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c){ return std::tolower(c); });

        if (choice == "i") {
            addNewCar(carTree, hash);
        } 
        else if (choice == "ins") {
            string filename;
            cout << "Enter file name: ";
            cin >> filename;
            loadCarsFromFile(carTree, hash, filename);
        }
        else if (choice == "d") {
            deleteCar(carTree, hash, undoStack);
        } 
        else if (choice == "f") {
           searchManager(hash);  
        } 
        else if (choice == "dis") {
            displayManager(carTree);
        } 
        else if (choice == "u") {
            undoDelete(carTree, hash, undoStack);
        } 
        else if (choice == "s") {
            hash.saveHashTableToFile("output.txt");
        } 
        else if(choice == "st") {
            cout << "Longest Collisions: " << hash.getLongestCollisions() << endl;
            cout << "Total Collisions: " << hash.getTotalCollisions() << endl;
            cout << "Load Factor: " << hash.getLoadFactor() << endl; 
        } 
        else if (choice == "t") {
            cout << "Team Members:\nBen Katzir\nKristine Koo\nKelvin Prabhu\nMazen Alziq\nTeam Leader: Ferit Kabil" << endl;
        } 
        else if (choice == "e") {
            hash.saveHashTableToFile("output.txt");
            cout << "Exiting program..." << endl;
        } 
        else if (choice=="h") {
            displayMenu();
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != "e");

    return 0;
}

// Load cars from a file into the binary search tree and hash table
void loadCarsFromFile(BinarySearchTree<antiqueCar>& tree, HashTable<antiqueCar>& hash, const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file: " << filename << endl;
    } else {
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string part;
    
            int id;
            string make, model, condition;
            int year;
    
            getline(ss, part, ',');
            id = stoi(part.substr(part.find(":") + 2));
            // cout << id << endl; // debug statement
            getline(ss, part, ',');
            make = part.substr(part.find(":") + 2);
    
            getline(ss, part, ',');
            model = part.substr(part.find(":") + 2);
    
            getline(ss, part, ',');
            year = stoi(part.substr(part.find(":") + 2));
    
            getline(ss, part);
            condition = part.substr(part.find(":") + 2);
    
            antiqueCar car(id, make, model, year, condition);
            tree.insert(car);
            hash.insert(car); // Add to hash table
        }
        cout << "Cars successfully loaded from " << filename << endl;
    }
}

/*
PROGRAMMER: Ferit Kabil 

Unit 1: Team Coordination

I was responsible for team coordination, data structure design, menus, and other related functions in main and integration.
I created the design of the data structures and coordinated them with the project. Furthermore, I created menus and related functions in the main. I coordinated the team for weekly reports and reminded them of the deadlines. After everyone did their own part, I ensured all parts of our project fit together smoothly, and I arranged and tested everything thoroughly. I corrected every missing part of the code, such as adding comment lines at the top of the functions that describe their purpose. I submitted each week's report, presentation poster, and presentations. I gave feedback to my team members, and I helped them solve their coding problems.

*/


// Display the main menu options
void displayMenu() {
    cout << "\nChoose from the menu (case insensitive):\n"
         << "INS - Insert from file\n"
         << "I - Add New Car (insert)\n"
         << "D - Delete a Car (Delete)\n"
         << "F -  Search Manager (Find car by car ID)\n"
         << "DIS - Display manager\n"
         << "U - Undo delete\n"
         << "S - Save to file\n"
         << "ST - Hash Statistics\n"
         << "T - Show team members (hidden menu option)\n"
         << "E - Exit program\n"
         << "Enter an option (H - for help): ";
}

// Add a new car to the binary search tree and hash table
void addNewCar(BinarySearchTree<antiqueCar>& tree, HashTable<antiqueCar>& hash) {
    int id, year;
    string make, model, condition;

    cout << "Enter car ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter car make: ";
    getline(cin, make);

    cout << "Enter car model: ";
    getline(cin, model);

    cout << "Enter car year: ";
    cin >> year;
    cin.ignore();

    cout << "Enter car condition: ";
    getline(cin, condition);

    antiqueCar car(id, make, model, year, condition);
    if(hash.search(car, id)==1) {
        cout << "Cannot add duplicates.\n";
    } else {
        if (tree.insert(car) && hash.insert(car)) {
            cout << "Car added successfully.\n";
        } else {
            cout << "Failed to add car.\n";
        }
    }
}

// Delete a car from the binary search tree and hash table
void deleteCar(BinarySearchTree<antiqueCar>& tree, HashTable<antiqueCar>& hash, Stack<antiqueCar>& s) {
    int id;
    cout << "Enter car ID to delete: ";
    cin >> id;

    antiqueCar carToDelete;
    carToDelete.setCarID(id);

    if (hash.search(carToDelete, id)) {
        s.push(carToDelete);
    }

    if (tree.remove(carToDelete)) {
        cout << "Car deleted successfully from the tree.\n";
        // Remove from the hash table as well
        if (hash.remove(carToDelete, carToDelete)) {
            cout << "Car deleted successfully from the hash table.\n";
        } else {
            cout << "Car not found in the hash table.\n";
        }
    } else {
        cout << "Car not found in the tree.\n";
    }
}

// Perform an in-order traversal of the binary search tree
void inOrderTraversal(const BinarySearchTree<antiqueCar>& tree) {
    cout << "Inorder Traversal:\n";
    tree.inOrder(hDisplay);
}

// Display the binary search tree in indented form
void displayIndentedTree(const BinarySearchTree<antiqueCar>& tree) {
    cout << "Indented Tree Display:\n";
    tree.printTree(iDisplay);
}

/* Contribution: Kristine Koo
I created the antiqueCar class file with the variables and setter/getter functions. 

I worked on the searchManager function, displayManager function, and
undoDelete function.

Before the project was presented, I detected an issue with the binary search
tree. Due to the input order, our BST was displaying as if the tree was a 
linked list, so I came up with the idea to scramble the data.

I helped the hash table unit by informing the team member what was wrong with
the way that the hash function was implemented, and how they could relocate it
to the proper location.

I integrated 3 of my features into main: 
1. Search manager
2. Undo delete
3. Display manager
*/

// Manage searching for a car by ID using the hash table
void searchManager(HashTable<antiqueCar>& hash) {
    cout << "--- Search Function --- \n";
    cout << "Enter Car ID [-1 to stop searching]:" << endl;
    int key;
    cin >> key;

    while (key != -1) {
        if (cin.fail()) {
            cin.clear(); // clear error state
            cin.ignore(100, '\n'); 
            cout << "Please enter a valid integer number." << endl;
        } else {
            antiqueCar carToDisplay; // initialized with default constructor carID value of -1

            if (hash.search(carToDisplay, key) && carToDisplay.getCarID()!=-1) { // if carToDisplay's carID is still -1 it means that the car has not been found and therefore carToDisplay kept the default constructor carID value of -1
                cout << "Car " << key << " exists in the data. \n";
                vDisplay(carToDisplay);
            } else {
                cout << "Car " << key << " does not exist. \n";
            }
        }
        cin >> key;
    }
}

// Allows the user to display all the values or the indented tree
void displayManager(BinarySearchTree<antiqueCar>& tree) {
    char option;

    cout << "Display Tree? Press any key (press Y for hidden menu option indented tree):";
    cin >> option;
    if ((option = tolower(option)) == 'y') {
        displayIndentedTree(tree);
    } else {
        inOrderTraversal(tree);
    }
}

// Allows the user to undo the last delete in the stack and puts it back in the
// BST and hash table.
void undoDelete(BinarySearchTree<antiqueCar>& tree, HashTable<antiqueCar>& hash, Stack<antiqueCar>& stack) {
    if (stack.isEmpty()) {
        cout << "There are no deletes to undo.\n";
    } else {
        antiqueCar car = stack.pop();
        tree.insert(car);
        hash.insert(car);
        cout << "Undo delete was successful.\n";
    }
}

/*
PROGRAMMER: MAZEN ALZIQ 

UNIT 5: FILE I/O

I was primarily responsible for implementing the save to file feature, as well as finalizing the hash table class.

Since file output relied on the hash table methods, I worked with Kelvin to improve
the hash table class and integrate it with methods in main, one of which being calculating hash size. 

Functions hashSize, countLines, nextPrime and isPrime were used corehently to calculate hash size. Count the lines in the file, multiply by 2, find the next prime number then use hashSize to save it into a variable which can be used to create hash objects.

saveHashTableToFile (in hashtable.h) relied on the hash table methods to save data from input files into an output file in hash table sequence. It was the most challenging to implement, and required  overloading the ostream operator.

A rehash method was created if the load factor was greater than 75%, it is used in the hash insert function within an if statement.
*/

// calculate hash size based on file, used to create hashtable objects
int hashSize(string file) {
    int size = countLines(file);
    return size;
}

// count lines in the file, used to determine hash size
int countLines(string file) {
    string line;
    int count = 0;

    // Open the input file to count the lines
    ifstream infile(file);
    if (!infile) {
        cerr << "Error opening file: " << file << endl;
        exit(1);
    }

    // Count lines in the input file
    while (getline(infile, line)) {
        count++;
    }
    infile.close(); 

    int size = nextPrime(count);
    return size;
}


// Checks if line count is a prime num, used to find hash size
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    } 
    if (num == 2) {
        return true;
    } 
    if (num % 2 == 0) {
        return false;
    } 
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    } 
    return true;
}

// Finds the closest prime number to line count, used to find hash size
int nextPrime(int num) {
    while (!isPrime(num)) {
        num++;
    }
    return num;
}

/*  Kelvin Prabhu
    I wrote the insert, delete, search, the hash function, and all other class method in Hashtable.h except for isPrime, reHash, nextPrime. I also did the entire hashnode.h. I added in the hash table unit into the main functions search manager, undo delete, loadCarsFromFile, addNewCar, deleteCarbut. I realized that I had some errors regarding what the hashtable methods took in. With a some feedback I was able to correct these issues. I also created the viewing hash statistics function in main and the corresponding methods in the hashtable.h file.    */
    