/* 
 CIS 22C
 Hashing - Linear Probe: insert, search, and delete 
 Written By: A. Student
 Reviewed & Modified by: Ben Katzir
*/
#include <iostream>
#include <sstream>
#include "HashTable.h"

using namespace std;

void buildHash(HashTable &hash);
void searchManager(const HashTable &hash);
void deleteManager(HashTable &hash);
void insertManager(HashTable &hash);

int main() {
    HashTable hash;
    
    buildHash(hash);
    cout << "Load Factor: " << hash.getLoadFactor() << endl;    
    searchManager(hash);
    deleteManager(hash);
    insertManager(hash);
    
    return 0;
}

void buildHash(HashTable &hash) {
    Student list[] = {{"Tom", 2.5}, {"Bob", 3.2}, {"Boc", 3.2}, {"Linda", 3.9}, {"Tim", 4.0},
                      {"Vic", 3.9}, {"Ann", 3.5}, {"Dylan", 3.1}, {"obB", 2.2}, {"oBb", 3.7},
                      {"Bbo", 3.3}, {"bBo", 3.9}, {"boB", 2.3}, {"", 0}};
   
    for (int i = 0; list[i].getName() != ""; i++) {
        hash.insert(list[i]);
    }
}

void searchManager(const HashTable &hash) {
    cout << endl << "~*~ Test Search ~*~" << endl;
    cout << "Enter name [# to stop searching]:" << endl;
    string name;
    getline(cin, name);
    while (name != "#") {
        Student item;
        int nc = hash.search(item, name);
        if (nc != -1) {
            cout << item.getName() << " " << item.getGpa() << " (" << nc << " collisions!)" << endl;
        } else {
            cout << name << " not found!" << endl;
        }
        getline(cin, name);
    }
}

void deleteManager(HashTable &hash) {
    cout << endl << "~*~ Test Delete ~*~" << endl;
    cout << "Enter name [# to stop deleting]:" << endl;
    string name;
    getline(cin, name);
    while (name != "#") {
        Student itemOut;
        if (hash.remove(itemOut, name)) {
            cout << itemOut.getName() << " " << itemOut.getGpa() << " - deleted!" << endl;
        } else {
            cout << name << " not found!" << endl;
        }
        cout << "Load Factor: " << hash.getLoadFactor() << endl;
        getline(cin, name);
    }
}

void insertManager(HashTable &hash) {
    cout << endl << "~*~ Test Insert - reject duplicates ~*~" << endl;
    cout << "Enter name [# to stop reading]:" << endl;
    string name;
    getline(cin, name);
    while (name != "#") {
        Student found;
        if (hash.search(found, name) != -1) {
            cout << "Duplicate key: " << found.getName() << " - rejected!" << endl;
        } else {
            cout << "Enter gpa:" << endl;
            double gpa;
            cin >> gpa;
            cin.ignore();
            Student newStudent(name, gpa);
            if (hash.insert(newStudent)) {
                int collisions = hash.search(found, name);
                cout << name << " - inserted (" << collisions << " collisions)" << endl;
            } else {
                cout << "Insertion failed: Hash table might be full." << endl;
            }
        }
        cout << "Load Factor: " << hash.getLoadFactor() << endl;
        cout << "Enter name [# to stop reading]:" << endl;
        getline(cin, name);
    }
}
