/*
Description:
The HashNode class template defines a node structure for a hash table. Each node holds an item of type T, along with attributes indicating its occupancy status (1 for occupied, 0 for empty from start, -1 for empty after removal) and the number of collisions encountered. It provides constructors for initialization and setters/getters for these attributes, facilitating efficient data storage and collision handling within the hash table.
*/
#ifndef _HASH_NODE
#define _HASH_NODE

template <class T>
class HashNode
{
private:
    T item;
    int occupied;// 1 -> occupied, 0 -> empty from start, -1 -> empty after removal 
    int noCollisions;

public:
    // constructors
    HashNode() {occupied = 0; noCollisions = 0;}
    HashNode(T anItem) {item = anItem; occupied = 1; noCollisions = 0;}
    HashNode(T anItem, int ocp, int nCol)
             {item = anItem; occupied = ocp; noCollisions = nCol;}
    // setters
    void setItem(const T & anItem) {item = anItem;}
    void setOccupied(int ocp) {occupied = ocp;}
    void setNoCollisions(int nCol) {noCollisions = nCol;}

    // getters
    T getItem() const {return item;}
    int getOccupied() const {return occupied;}
    int getNoCollisions() const {return noCollisions;}

};

#endif
