#include <iostream>
using namespace std;

const int TABLE_SIZE = 20;

class Entry
{
public:
    int key;
    int value;
    Entry* next;

    Entry(int n, int m)
    {
        key = n;
        value = m;
        next = nullptr;
    }
    Entry()
    {
        key = -1;
        value = 0;
        next = nullptr;
    }
};

class HashTableChaining
{
private:
    Entry** table; //two asterisks to declare a pointer to a pointer to an entry.
    int numOfCollisions;
    int elements;

    int hashFunction(int k)
    {
        return k % TABLE_SIZE;
    }

public:
    HashTableChaining()
    {
        table = new Entry*[TABLE_SIZE];
        elements = 0;
        numOfCollisions = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = nullptr;
        }
    }
    ~HashTableChaining()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            Entry* current = table[i];
            while (current != nullptr)
            {
                Entry* next = current-> next;
                delete current;
                current = next;
            }
        }

        delete[] table; 
    }

    int getCollisions()
    {
        return numOfCollisions;
    }

void put(int k, int v)
{
    int index = hashFunction(k);
    Entry* newentry = new Entry(k, v);

    if (table[index] == nullptr)
    {
        table[index] = newentry;
    }
    else
    {
        // A collision happens 
        numOfCollisions++;
        
        Entry* iterator = table[index];
        while (iterator->next != nullptr)
        {
            iterator = iterator->next;
            numOfCollisions++;
        }
        iterator->next = newentry;
    }

    elements++; 
}



int erase(int k)
    {
        int index = hashFunction(k);
        int removedvalue;
        Entry* iterator = table[index];
        if(elements == 0)
        {
            cout << "Hash Table is empty." << endl;
            return -1;
        }
        if(iterator == nullptr)
        {
            cout << "Key is not found in the hash table." << endl;
            return -1;
        }
        else
        {
            if(iterator->next == nullptr)
            {
                removedvalue = iterator->value;
                delete(iterator);
                table[index] = nullptr;
                elements--;
                return removedvalue;
            }
            else
            {
                table[index] = iterator->next;
                iterator->next = nullptr;
                removedvalue = iterator->value;
                delete(iterator);
                elements--;
                return removedvalue;
            }
        }
       
    }

    int find(int k)
    {
        int index = hashFunction(k);
        int foundvalue;
        Entry* iterator = table[index];
        if(elements == 0)
        {
            cout << "Hash Table is empty." << endl;
            return -1;
        }
        if(iterator == nullptr)
        {
            cout << "Key is not found in the hash table." << endl;
            return -1;
        }
        else
        {
            foundvalue = iterator->value;
            return foundvalue;
        }
       
    }


    int size()
    {
        return elements;
    }

    bool isEmpty()
    {
        if (elements == 0)
        return true;
        else
        return false;
    }
        
};

class HashTableLinearProbing 
{
private:
    Entry** table;
    int elements;
    int numOfCollisions;
    int hashfunction(int k)
    {
        return k % TABLE_SIZE;
    }
public:
    HashTableLinearProbing()
        {
            table = new Entry*[TABLE_SIZE];
            elements = 0;
            numOfCollisions = 0;
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                table[i] = nullptr;
            }
        }
    void put(int k,int v)
    {
        int originalindex = hashfunction(k);
        Entry* newentry = new Entry(k,v);
        if (elements == TABLE_SIZE)
        {
            cout << "Table is full." << endl;
            return;
        }
        if (table[originalindex] == nullptr)
        {
            table[originalindex] = newentry;
            elements++;
            return;
        }
        else
        {
            int index = (originalindex+1) % TABLE_SIZE;
            numOfCollisions++;
            while(table[index] != nullptr)
            {
                index = (index +1) % TABLE_SIZE;
                numOfCollisions++;
            }
            table[index] = newentry;
            elements++;
            return;
        }
    }
    int erase(int k)
    {
        int originalindex = hashfunction(k);
        int tempvalue;
        
        int index = originalindex;
        bool found = false;

       //looking for the key, exits when it finds it
        do {
            if (table[index] != nullptr && table[index]->key == k) {
                found = true;
                break;
            }
            
            index = (index + 1) % TABLE_SIZE;
        } while (index != originalindex);

        if (found) {
            tempvalue = table[index]->value;
            table[index] = nullptr; // Mark the slot as deleted
            elements--;
            return tempvalue;
        }
        
        cout << "Key does not exist in table" << endl;
        return -1;
    }


    //essentially identical to erase, just not removing the value we find
    int find(int k)
    {
        int originalindex = hashfunction(k);
        int tempvalue;
        
        int index = originalindex;
        bool found = false;

        // looking for the key in the array
        do {
            if (table[index] != nullptr && table[index]->key == k) {
                found = true;
                break;
            }
            
            index = (index + 1) % TABLE_SIZE;
        } while (index != originalindex);

        if (found) 
        {
            tempvalue = table[index]->value;
            return tempvalue;
        }
        
        cout << "Key does not exist in table" << endl;
        return -1;
    }

    int getCollisions()
    {
        return numOfCollisions;
    }

    int size()
    {
        return elements;
    }

    bool isEmpty()
    {
        if(elements == 0)
        return true;
        else
        return false;
    }
};
