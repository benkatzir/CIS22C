// Specification file for the HashTable class
// Written By: A. Student
// Changed by: Ben Katzir

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashNode.h"

template<class T>
class HashTable
{
private:
    HashNode<T>* hashAry;
    int hashSize;
    int count;

public:
    HashTable() { count = 0; hashSize = 53; hashAry = new HashNode<T>[hashSize]; }
    HashTable(int n) { count = 0; hashSize = n; hashAry = new HashNode<T>[hashSize]; }
    ~HashTable() { delete[] hashAry; }

    int getCount() const { return count; }
    int getSize() const { return hashSize; }
    double getLoadFactor() const { return 100.0 * count / hashSize; }
    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == hashSize; }

    bool insert(const T &itemIn, int h(const T &key, int size));
    bool remove(T &itemOut, const T &key, int h(const T &key, int size));
    int search(T &itemOut, const T &key, int h(const T &key, int size)) const;
};

/*~*~*~*
   Insert an item into the hash table
   It does not reject duplicates
*~**/
template<class T>
bool HashTable<T>::insert(const T &itemIn, int h(const T &key, int size))
{
    if (count == hashSize)
        return false;

    int bucket = h(itemIn, hashSize);
    int bucketsProbed = 0;

    while (bucketsProbed < hashSize)
    {
        if (hashAry[bucket].getOccupied() <= 0)
        {
            hashAry[bucket].setItem(itemIn);
            hashAry[bucket].setOccupied(1);
            hashAry[bucket].setNoCollisions(bucketsProbed);
            count++;
            return true;
        }

        bucket = (bucket + 1) % hashSize;
        bucketsProbed++;
    }

    return false;
}

/*~*~*~*
   Removes the item with the matching key from the hash table
   if found:
     - copies data in the hash node to itemOut
     - replaces data in the hash node with an empty record (occupied = -1: deleted!)
     - returns true
   if not found:
     - returns false
*~**/
template<class T>
bool HashTable<T>::remove(T &itemOut, const T &key, int h(const T &key, int size))
{
    int bucket = h(key, hashSize);
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

/*~*~*~*
   hash search - linear probe
   if found:
      - copy data to itemOut
      - returns the number of collisions for this key
   if not found, returns -1
*~**/
template<class T>
int HashTable<T>::search(T &itemOut, const T &key, int h(const T &key, int size)) const
{
    int bucket = h(key, hashSize);
    int bucketsProbed = 0;

    while (bucketsProbed < hashSize && hashAry[bucket].getOccupied() != 0)
    {
        if (hashAry[bucket].getOccupied() == 1 && hashAry[bucket].getItem() == key)
        {
            itemOut = hashAry[bucket].getItem();
            return hashAry[bucket].getNoCollisions();
        }

        bucket = (bucket + 1) % hashSize;
        bucketsProbed++;
    }

    return -1;
}

#endif // HASHTABLE_H_
