// Implementation file for the Hash class
// Written By: A. Student
// Changed by: Ben Katzir

#include <string>

#include "HashTable.h"

using namespace std;

/*~*~*~*
  A simple hash function 
 *~**/
int HashTable::_hash(string key) const
{
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % hashSize;
};

/*~*~*~*
  hash insert - linear probe
*~**/

bool HashTable::insert(const Student &itemIn)
{
    if ( count == hashSize)
        return false;
   /* write your code here */
    // Hash function determines initial bucket
    int bucket = _hash(itemIn.getName());
    int bucketsProbed = 0;
    int N = hashSize;
    bool itemSet = false;
    // Linear probing to find an empty bucket
    while (bucketsProbed < N && itemSet == false) {
        // Insert item in next empty bucket
        if (hashAry[bucket].getOccupied() == 0) {
            hashAry[bucket].setItem(itemIn);
            hashAry[bucket].setOccupied(1);
            hashAry[bucket].setNoCollisions(bucketsProbed);
            count++;
            itemSet = true;
        }

        // Increment bucket index
        bucket = (bucket + 1) % N;

        // Increment number of buckets probed
        ++bucketsProbed;
    }

    return true;
}

/*~*~*~*
   hash delete - linear probe
*~**/

bool HashTable::remove(Student &itemOut)
{
    return false;
}

/*~*~*~*
   hash search - linear probe
   search for key
   if found: 
      - copy data to itemOut
      - copy number of collisions for this key to noCol
      - returns true
   if not found, returns false
*~**/
bool HashTable::search(Student &itemOut, int &noCol, string key)
{
   /* write your code here */
    // Hash function determines initial bucket
    int bucket = _hash(key);
    int bucketsProbed = 0;

    // Start probing
    while ((hashAry[bucket].getOccupied() != 0) && (bucketsProbed < hashSize)) {
        // Check if the current bucket contains the key
        if (hashAry[bucket].getOccupied() == 1 && hashAry[bucket].getItem().getName() == key) {
            itemOut = hashAry[bucket].getItem();  // Copy data to itemOut
            noCol = hashAry[bucket].getNoCollisions();  // Copy number of collisions for this key to noCol
            return true;  // Item found
        }

        // Increment bucket index
        bucket = (bucket + 1) % hashSize;

        // Increment number of buckets probed
        ++bucketsProbed;
    }

    return false;  // Item not found
}