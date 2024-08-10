// Specification file for the Hash class

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashNode.h"

using std::string;

class HashTable
{
private:
	HashNode* hashAry;
	int hashSize;
   int count;
	
public:
	HashTable() { count = 0; hashSize = 53; hashAry = new HashNode[hashSize]; }
	HashTable(int n)	{ count = 0; hashSize = n;	hashAry = new HashNode[hashSize]; }
	~HashTable(){ delete [] hashAry; }

	int getCount() const	{ return count; }
   int getSize() const { return hashSize; }
   double getLoadFactor() const {return 100.0 * count / hashSize; }
   bool isEmpty() const	{ return count == 0; }
   bool isFull()  const	{ return count == hashSize; }
    
   bool insert( const Student &itemIn );
   bool remove( Student &itemOut );
   bool search( Student &itemOut, int &noCol, string key);
    
private:
   int _hash(string key) const;
};

#endif // HASHTABLE_H_
