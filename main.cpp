#include "hash.h"
#include <iostream>

using namespace std;

int main() {
    // Testing HashTableChaining
    HashTableChaining chainingTable;

    // put some key-value pairs without collisions
    chainingTable.put(5, 10);
    chainingTable.put(15, 20);
    chainingTable.put(7, 30);
    chainingTable.put(2, 40);
    chainingTable.put(17, 50);
    chainingTable.put(12, 60);

    chainingTable.put (13,1); 
    chainingTable.put (13,2); //collide
    chainingTable.put (13,4); //collide
    chainingTable.put (13,4); //collide
    chainingTable.put (13,5); //collide


    // Display collision count
    cout << "Collision count (chaining): " << chainingTable.getCollisions() << endl;

    // erase some elements
    cout << "erased: " << chainingTable.erase(5) << " (Expected: 10)" << endl;
    cout << "erased: " << chainingTable.erase(12) << " (Expected: 60)" << endl;
    cout << "erased: " << chainingTable.erase(13) << " (Expected: 1)" << endl;
    cout << "erased: " << chainingTable.erase(13) << " (Expected: 2)" << endl;
    cout << "erased: " << chainingTable.erase(13) << " (Expected: 4)" << endl;
    cout << "erased: " << chainingTable.erase(13) << " (Expected: 4)" << endl;
    cout << "erased: " << chainingTable.erase(13) << " (Expected: 5)" << endl;
    cout << "erased: " << chainingTable.erase(13) << " (Expected: error)" << endl;
    cout << "found: " << chainingTable.find(7) << " (Expected: 30)" << endl;

    // Display collision count
    cout << "Collision count (chaining): " << chainingTable.getCollisions() << endl;

    cout << "WE're now going to test the other implementation." << endl;
    //testing probing implementation
    HashTableLinearProbing probingTable;

    /*probingTable.put(4,5);
    probingTable.put(5,6);
    cout << probingTable.erase(4) << " (Expected 5)" << endl;
    cout << probingTable.erase(5) << " (Expected 6)" << endl;
    cout << probingTable.erase(5) << endl;*/
    probingTable.put(3,2);//collision
    probingTable.put(3,3);//collsion
    probingTable.put(3,5);//collision
    cout << probingTable.getCollisions() << endl;
    cout << "Expected 2: " << probingTable.erase(3) << endl;
    cout << "Expected 3: " << probingTable.erase(3) << endl;
    cout << "Expected 5: " << probingTable.erase(3) << endl;
    cout << "Expected error: " << probingTable.erase(3) << endl;
    cout << "Expected error: " << probingTable.find(3) << endl;
    probingTable.put(3,2);
    cout << "Expected 2: " << probingTable.erase(3) << endl;
    return 0;
}
