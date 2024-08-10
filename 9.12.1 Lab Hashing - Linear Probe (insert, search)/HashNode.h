// Specification file for the HashNode class

#ifndef _HASH_NODE
#define _HASH_NODE

#include "Student.h"

using std::string;

class HashNode
{
private:
    Student item;
    int occupied;   // 1 -> occupied, 0 -> empty 
    int noCollisions;

public:
    // constructors
    HashNode() {occupied = 0; noCollisions = 0;}
    HashNode(Student anItem) {item = anItem; occupied = 1; noCollisions = 0;}
    HashNode(Student anItem, int ocp, int nCol)
             {item = anItem; occupied = ocp; noCollisions = nCol;}
    // setters
    void setItem(const Student & anItem) {item = anItem;}
    void setOccupied(int ocp) {occupied = ocp;}
    void setNoCollisions(int nCol) {noCollisions = nCol;}
    
    // getters
    Student getItem() const {return item;}
    int getOccupied() const {return occupied;}
    int getNoCollisions() const {return noCollisions;}
};

#endif
