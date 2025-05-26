#include "Utils.h"
#include <sstream>

// converts an integer to a hexadecimal string
std::string intToHexStream(int num) {
    std::stringstream ss;
    ss << std::hex << num;
    return ss.str();
}

// creates a "hash" by adding up all character values and converting to hex
std::string computeHash(int index, const std::string& timestamp, const std::string& data, const std::string& prevHash) {
    std::string content = std::to_string(index) + timestamp + data + prevHash;
    int sum = 0;
    for (char ch : content) {
        sum += static_cast<int>(ch); // add ASCII value of each character
    }
    return intToHexStream(sum); // convert sum to hex string
}
