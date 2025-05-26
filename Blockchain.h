#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <string>

// Blockchain class that manages an array of Block pointers
class Blockchain {
private:
    Block* chain[100]; // array to store up to 100 blocks
    int size; // current number of blocks in the chain

public:
    Blockchain(); // constructor that starts the chain (adds genesis)

    void addBlock(const std::string& data); // adds a normal block
    void addBlock(const std::string& data, bool isGenesis); // adds a block, can be genesis

    void displayChain(); // prints all blocks in the chain
    bool validateChain(); // checks if the chain is valid

    void saveToFile(const std::string& filename); // saves blockchain to a file
    void loadFromFile(const std::string& filename); // loads blockchain from a file
};

#endif
