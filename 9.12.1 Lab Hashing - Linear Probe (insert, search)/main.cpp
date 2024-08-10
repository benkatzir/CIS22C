/*
 CIS 22C
 
 This program builds and searches a hash table.
  
 Written by: A. Student
 Reviewed & Modified by: Ben Katzir
 IDE: Visual Studio Code
 
 */
#include <iostream>
#include <sstream>
#include <cctype>

#include "HashTable.h"

using namespace std;

void buildHash(HashTable &hash);
void searchManager(HashTable &hash);

int main()
{    
    HashTable hash;
    string option;
    
    /* call buildHash() */
    buildHash(hash);
    
    cout << "Load Factor: " << hash.getLoadFactor()/* getLoadFactor() */ << endl;
    
    /* call searchManager */
    searchManager(hash);    
 
    return 0;
}

/* **************************************************
This function builds a hash table with data from the keyboard.
It calls the insert() function that inserts the new data at the right location in the hash table.
An input line contains the gpa of a student follow by name (assume it is a single word name)
To stop reading enter "#"
************************************************** */
void buildHash(HashTable &hash)
{
   string line;
   cout << "Enter gpa and name [# to stop reading]:" << endl;
   getline(cin, line);
   while (line != "#")
   {
      stringstream temp(line); // create a stringstream named temp with data from line
      double gpa;
      string name;
      temp >> gpa;  // read gpa from temp
      temp >> name; // read name from temp
      Student newStu(name, gpa);
      hash.insert(newStu);
      getline(cin, line);
   }
   
}

/* **************************************************
This function searches a hash table with user provided data.
It calls the hash search function in a loop.
To stop searching enter "#"
************************************************** */
void searchManager(HashTable &hash)
{
   string name;
   cout << "Enter name [# to stop searching]:" << endl;
   getline(cin, name);
   while (name != "#")
   {
        Student item;
        int nc;
        if (hash.search(item, nc, name))
        {
            cout << item.getName() << " " << item.getGpa() << " (" << nc << " collisions!)" << endl;
        }
        else
        {
            cout << name << " not found!" << endl;
        }
        getline(cin, name);
    }
   
}


