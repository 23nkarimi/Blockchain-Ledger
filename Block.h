/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 4: Blockchain Ledger
*/

#ifndef BLOCK_H
#define BLOCK_H

#include <string>

// Block class represents one block in the blockchain
class Block {
public:
    int index; // block's position in the chain
    std::string timestamp; // time the block was created
    std::string data; // info stored in the block
    std::string previousHash; // hash of the previous block
    std::string currentHash; // this block's hash

    Block(); // default constructor
    Block(int idx, const std::string& dt, const std::string& prevHash); // constructor w/ values
};

#endif
