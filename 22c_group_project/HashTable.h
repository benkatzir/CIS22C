/*
Description:
The HashTable class template implements a hash table for storing objects of type T. It supports insertion, removal, and searching based on a key, with collision resolution using open addressing. Additional features include load factor management, dynamic resizing, and file-based data saving, ensuring efficient data handling.
*/
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashNode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

template<class T>
class HashTable
{
private:
    HashNode<T>* hashAry;
    int hashSize;
    int count;
    int collisions;
    int totalCollisions;
    int longestCollisionPath;

    // Private functions
    int key_to_index(const T &key) const;
    int nextPrime(int num);
    bool isPrime(int num);
    void rehash();

public:
    // Constructors and Destructor
    HashTable() { count = 0; collisions = 0; totalCollisions = 0; longestCollisionPath = 0; hashSize = 61; hashAry = new HashNode<T>[hashSize]; }
    HashTable(int n) { count = 0; collisions = 0; totalCollisions = 0; longestCollisionPath = 0; hashSize = n; hashAry = new HashNode<T>[hashSize]; }
    ~HashTable() { delete[] hashAry; }

    // Accessors
    int getCount() const { return count; }
    int getSize() const { return hashSize; }
    double getLoadFactor() const { return 100.0 * count / hashSize; }
    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == hashSize; }
    int getLongestCollisions() const { return longestCollisionPath; }
    int getTotalCollisions() const { return totalCollisions; }
    int getCollisions() const { return collisions; }

    // Mutators
    bool insert(const T &itemIn);
    bool remove(T &itemOut, const T &key);
    int search(T &itemOut, const T &key) const;
    void saveHashTableToFile(const std::string& filename) const;
};

// Computes the hash index for a given key.
template<class T>
int HashTable<T>::key_to_index(const T &key) const {
    std::string k = std::to_string(key.getCarID());
    int sum = 0;
    for (int i = 0; k[i]; i++)
        sum += k[i];
    return sum % hashSize;
}

// Inserts an item into the hash table.
template<class T>
bool HashTable<T>::insert(const T &itemIn)
{
    if (count == hashSize) {
        return false;
    }
    
    // rehash if load factor is > 75%. Create new hash table and delete the old one
    if (getLoadFactor() > 75) {
        rehash();
    }

    int bucket = key_to_index(itemIn);
    int bucketsProbed = 0;

    while (bucketsProbed < hashSize)
    {
        if (hashAry[bucket].getOccupied() <= 0)
        {
            hashAry[bucket].setItem(itemIn);
            hashAry[bucket].setOccupied(1);
            hashAry[bucket].setNoCollisions(bucketsProbed);
            count++;
            collisions = bucketsProbed;

            totalCollisions += bucketsProbed;
            if (bucketsProbed > longestCollisionPath) {
                longestCollisionPath = bucketsProbed;
            }
            return true;
        }

        bucket = (bucket + 1) % hashSize;
        bucketsProbed++;
    }
    return false;
}

// Removes an item from the hash table using the given key.
template<class T>
bool HashTable<T>::remove(T &itemOut, const T &key)
{
    int bucket = key_to_index(key);
    int bucketsProbed = 0;

    while (bucketsProbed < hashSize && hashAry[bucket].getOccupied() != 0)
    {
        if (hashAry[bucket].getOccupied() == 1 && hashAry[bucket].getItem() == key)
        {
            itemOut = hashAry[bucket].getItem();
            hashAry[bucket].setOccupied(-1);
            count--;
            return true;
        }

        bucket = (bucket + 1) % hashSize;
        bucketsProbed++;
    }

    return false;
}

// Searches for an item using the given key.
template<class T>
int HashTable<T>::search(T &itemOut, const T &key) const
{
    int bucket = key_to_index(key);
    int bucketsProbed = 0;

    while (bucketsProbed < hashSize && hashAry[bucket].getOccupied() != 0)
    {
        if (hashAry[bucket].getOccupied() == 1 && hashAry[bucket].getItem() == key)
        {
            itemOut = hashAry[bucket].getItem();
            return 1;
        }

        bucket = (bucket + 1) % hashSize;
        bucketsProbed++;
    }

    return -1;
}


// Saves the contents of the hash table to a file with the given filename.
template<class T>
void HashTable<T>::saveHashTableToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    for (int i = 0; i < hashSize; ++i) {
        if (hashAry[i].getOccupied() == 1) {
            outfile << hashAry[i].getItem() << std::endl;
        }
    }
    outfile.close();
    std::cout << "Hash table saved to " << filename << std::endl;
}

// Rehashes the hash table to a new size when load factor exceeds 75%.
template<class T>
void HashTable<T>::rehash() {
    int oldSize = hashSize;
    hashSize = nextPrime(hashSize * 2);
    HashNode<T>* oldHashAry = hashAry;
    hashAry = new HashNode<T>[hashSize];
    count = 0;
    totalCollisions = 0;
    longestCollisionPath = 0;

    for (int i = 0; i < oldSize; ++i) {
        if (oldHashAry[i].getOccupied() == 1) {
            insert(oldHashAry[i].getItem());
        }
    }

    delete[] oldHashAry;
}

// Checks if line count is a prime num, used to find hash size
template<class T>
bool HashTable<T>::isPrime(int num) {
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
template<class T>
int HashTable<T>::nextPrime(int num) {
    while (!isPrime(num)) {
        num++;
    }
    return num;
}


#endif 
