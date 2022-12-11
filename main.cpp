#include <iostream>
#include <stdint.h>
#include <vector>

struct hashMap {
    //Using an int variable, we can create the hash table with one of the three ways 
    std::vector<int> hashTable;
    // The hash starts with no elements 
    int elements = 0;
    // The hash code is created with that can take in the hash code
    int compression(uint64_t hash) 
    {
        // The starting size of the hash table is given and int for size
        int size = hashTable.size();
        // To prepare for the collusion
        int collusions = 0;
        // The bucket index that will be storing the data
        if (elements == size) 
        {
            hashTable.resize(size * 2);
            size = hashTable.size();
        }
        // hash % size can create the key used for the bucket
        int key = hash % size;
        // This allows for the key to find a collusion that hasn't already been used
        while (hashTable[key] != NULL) 
        {
            collusions++;
            key = (hash + collusions) % size;
        }
        // The key and the hash will now become equal
        hashTable[key] = hash;
        elements++;
        return key;
    }
};
int main() 
{
    // Establishing the size of the hash table 
    hashMap test;
    test.hashTable.resize(15);
    // The beginning of case one, for the output with no collusion
    for (int i = 1; i < 15; i++) 
    {
        // Outputting all elements of the hash table with their corresponding position
        // Insures the hash has atleast 11 distinct inputs, in this case its 15
        std::cout << "Compression(" << i << "): " << test.compression(i) << std::endl;
    }
    std::cout << "\nOutput of case 1"<< std::endl;
    std::cout << "Hash table with no collusion: ";
    for (int i = 0; i < test.hashTable.size(); i++) 
    {
        std::cout << test.hashTable[i] << ", ";
    }
    // Establishing where the collusion is going to be
    std::cout << "\n\nCompression(15): " << test.compression(12) << std::endl;
    // This is where the case with a collusion will be for case 2
    std::cout << "\nOutput of case 2" << std::endl;
    std::cout << "Hash table with collusion: ";
    for (int i = 0; i < test.hashTable.size(); i++) 
    {
        std::cout << test.hashTable[i] << ", ";
    }
}
