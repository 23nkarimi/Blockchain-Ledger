/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 4: Blockchain Ledger
*/

#include "Blockchain.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

// constructor - initializes size and adds the genesis block
Blockchain::Blockchain() {
    size = 0;
    addBlock("Genesis Block", true);
}

// adds a new block to the chain (handles genesis too)
void Blockchain::addBlock(const std::string& data, bool isGenesis) {
    std::string prevHash = (size == 0) ? "0" : chain[size - 1]->currentHash;
    chain[size] = new Block(size, data, prevHash);
    size++;

    // print block info to console
    std::cout << (isGenesis ? "🧱 Genesis Block Created 🧱\n" : "🧱 New Block Added 🧱\n");
    std::cout << "Index: " << chain[size - 1]->index << "\n";
    std::cout << "Timestamp: " << chain[size - 1]->timestamp;
    std::cout << "Data: " << chain[size - 1]->data << "\n";
    std::cout << "Previous Hash: " << chain[size - 1]->previousHash << "\n";
    std::cout << "Hash: " << chain[size - 1]->currentHash << "\n\n";
}

// wrapper to add a regular block (not genesis)
void Blockchain::addBlock(const std::string& data) {
    addBlock(data, false);
}

// prints the entire blockchain to console
void Blockchain::displayChain() {
    std::cout << "\n🔗 Blockchain State\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Index: " << chain[i]->index << "\n"
                  << "Timestamp: " << chain[i]->timestamp
                  << "Data: " << chain[i]->data << "\n"
                  << "Previous Hash: " << chain[i]->previousHash << "\n"
                  << "Hash: " << chain[i]->currentHash << "\n\n";
    }
}

// checks if each block’s hash and links are valid
bool Blockchain::validateChain() {
    std::cout << "\nPerforming blockchain validation..." << std::endl;
    for (int i = 2; i < size; i++) {
        std::cout << chain[i - 1]->index << chain[i - 1]->timestamp << chain[i - 1]->data << chain[i - 1]->previousHash << std::endl;
        std::string expectedHash = computeHash(chain[i - 1]->index, chain[i - 1]->timestamp, chain[i - 1]->data, chain[i - 1]->previousHash);
        if (chain[i - 1]->currentHash != expectedHash) {
            std::cout << "Block " << i - 1 << " has an invalid current hash!" << std::endl;
            std::cout << "Result: Blockchain is invalid!⛔️" << std::endl;
            return false;
        }
        if (chain[i]->previousHash != chain[i - 1]->currentHash) {
            std::cout << "Block " << i << " has a mismatched previous hash!" << std::endl;
            std::cout << "Result: Blockchain is invalid!⛔️" << std::endl;
            return false;
        }
    }
    std::cout << "Result: Blockchain is valid ✅" << std::endl;
    return true;
}

// saves blockchain data to a file (pipe-separated)
void Blockchain::saveToFile(const std::string& filename) {
    std::ofstream out(filename);
    for (int i = 0; i < size; i++) {
        out << chain[i]->index << "|"
            << chain[i]->timestamp.substr(0, chain[i]->timestamp.length() - 1) << "|"
            << chain[i]->data << "|"
            << chain[i]->previousHash << "|"
            << chain[i]->currentHash << std::endl;
    }
    out.close();
    std::cout << "Blockchain saved to file: " << filename << std::endl;
}

// loads blockchain data from a file
void Blockchain::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    std::string line;
    size = 0;
    while (getline(in, line)) {
        std::stringstream ss(line);
        std::string idx, ts, dt, prevH, currH;
        getline(ss, idx, '|');
        getline(ss, ts, '|');
        getline(ss, dt, '|');
        getline(ss, prevH, '|');
        getline(ss, currH);

        chain[size] = new Block();
        chain[size]->index = std::stoi(idx);
        chain[size]->timestamp = ts + "\n";
        chain[size]->data = dt;
        chain[size]->previousHash = prevH;
        chain[size]->currentHash = currH;
        size++;
    }
    in.close();
    std::cout << "Blockchain loaded from file: " << filename << std::endl;
}
