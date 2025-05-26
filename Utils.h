/*
Full name: Nima Karimi
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 4: Blockchain Ledger
*/

#ifndef UTILS_H
#define UTILS_H

#include <string>

// converts an int to a hex string
std::string intToHexStream(int num);

// creates a simple hash from block info
std::string computeHash(int index, const std::string& timestamp, const std::string& data, const std::string& prevHash);

#endif
