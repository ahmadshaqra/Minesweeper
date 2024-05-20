/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Main Application File
 **************************************************/

#include "main.h"

int main() {

    // testing utility class
    Utility::displayTitle();
    std::string string = Utility::getString("  Enter String: ");
    std::cout << "  " << string << "\n\n";
    int integer = Utility::getInteger("  Enter Integer: ");
    std::cout << "  " << integer << "\n\n";
    char character = Utility::getCharacter("  Enter Character: ");
    std::cout << "  " << character << "\n";
    Utility::wait();
    Utility::clearScreen();
    Utility::displayTitle();
    std::cout << "  Hello world!\n";
    Utility::wait();

    // exit
    return 0;
}
