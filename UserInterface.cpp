#include "UserInterface.h"
#include "Blockchain.h"
#include <iostream>
#include <limits>

#define RED     "\033[1;31m"  // sets text color to red
#define RESET   "\033[0m"     // resets text color to default

// shows the menu options to the user
void displayMenu() {
    std::cout << "Welcome to your Panther Blockchain Ledger:\n";
    std::cout << "1. Add a New Block\n";
    std::cout << "2. Display the Blockchain\n";
    std::cout << "3. Validate the Blockchain\n";
    std::cout << "4. Save Blockchain to File\n";
    std::cout << "5. Load Blockchain from File\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

// main loop for interacting with the user
void UserInterface::run() {
    Blockchain blockchain; // create blockchain instance
    int choice;
    std::string input;

    while (true) {
        displayMenu(); // show menu options
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer

        switch (choice) {
            case 1: { // add new block
                std::cout << "Enter block data: ";
                std::getline(std::cin, input);
                std::cout << RED << input << RESET << std::endl; // show data in red
                blockchain.addBlock(input);
                break;
            }
            case 2: // show full blockchain
                blockchain.displayChain();
                break;
            case 3: // validate the blockchain
                blockchain.validateChain();  
                break;
            case 4: { // save to file
                std::string filename;
                std::cout << "Enter filename to save the blockchain: ";
                std::getline(std::cin, filename);
                blockchain.saveToFile(filename);
                break;
            }
            case 5: { // load from file
                std::string filename;
                std::cout << "Enter filename to load the blockchain: ";
                std::getline(std::cin, filename);
                blockchain.loadFromFile(filename);
                break;
            }
            case 6: // quit
                std::cout << "Exiting...\n";
                return;
            default: // invalid input
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }
}
