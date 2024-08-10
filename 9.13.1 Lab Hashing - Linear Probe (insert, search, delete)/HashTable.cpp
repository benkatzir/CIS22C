// Implementation file for the Hash class
// Written By: A. Student
// Reviewed & Modified by: Ben Katzir
#include <string>
#include "HashTable.h"

using namespace std;

/*~*~*~*
  A simple hash function 
 *~**/
int HashTable::_hash(string key) const {
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % hashSize;
}

/*~*~*~*
  hash insert - linear probe
     - returns false if the hash table is full
     - returns true if itemIn is inserted into the hash table
*~**/
bool HashTable::insert(const Student &itemIn) {
    if (count == hashSize) return false;

    int bucket = _hash(itemIn.getName());
    int bucketsProbed = 0;

    while (bucketsProbed < hashSize) {
        if (hashAry[bucket].getOccupied() <= 0) {
            hashAry[bucket] = HashNode(itemIn, 1, bucketsProbed);
            count++;
            return true;
        }

        bucket = (bucket + 1) % hashSize;
        bucketsProbed++;
    }

    return false;
}

/*~*~*~*
   hash delete - linear probe
   - looks for key in hash table
   - if found:
       - copies its data to itemOut 
       - replaces data in the hash node with an "empty" record
       - returns true
   - if not found - returns false
*~**/
bool HashTable::remove(Student &itemOut, string key) {
    int bucket = _hash(key);
    int bucketsProbed = 0;

    while (hashAry[bucket].getOccupied() != 0 && bucketsProbed < hashSize) {
        if (hashAry[bucket].getOccupied() == 1 && hashAry[bucket].getItem().getName() == key) {
            itemOut = hashAry[bucket].getItem();
            hashAry[bucket].setOccupied(-1); // Mark as EmptyAfterRemoval
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
int HashTable::search(Student &itemOut, string key) const {
    int bucket = _hash(key);
    int bucketsProbed = 0;

    while (hashAry[bucket].getOccupied() != 0 && bucketsProbed < hashSize) {
        if (hashAry[bucket].getOccupied() == 1 && hashAry[bucket].getItem().getName() == key) {
            itemOut = hashAry[bucket].getItem();
            return bucketsProbed;
        }

        bucket = (bucket + 1) % hashSize;
        bucketsProbed++;
    }

    return -1;
}
