#include "Block.h"
#include "Utils.h"  
#include <ctime>
#include <sstream>

// default constructor - sets everything to empty or 0
Block::Block()
    : index(0), timestamp(""), data(""), previousHash(""), currentHash("") {}

// constructor that sets index, data, and previous hash, then generates timestamp and hash
Block::Block(int idx, const std::string& dt, const std::string& prevHash)
    : index(idx), data(dt), previousHash(prevHash) {
    
    // gets current time as the block's timestamp
    time_t now = time(0);
    timestamp = ctime(&now);

    // creates the block's hash using all the info
    currentHash = computeHash(index, timestamp, data, previousHash);
}
