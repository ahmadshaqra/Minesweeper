/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Utility Header File
 **************************************************/

#ifndef MINESWEEPER_UTILITY_H
#define MINESWEEPER_UTILITY_H

// including modules
#include <iostream>
#include <string>
#include <Constants.h>

class Utility {

public:

    // class methods
    static void wait();
    static void clearScreen();
    static void displayTitle();
    static std::string getString(const std::string& prompt);
    static int getInteger(const std::string& prompt);
    static char getCharacter(const std::string& prompt);
};

#endif //MINESWEEPER_UTILITY_H
