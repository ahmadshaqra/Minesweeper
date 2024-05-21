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
#include <cmath>

// including classes
#include <Constants.h>

// declaring functions
void wait();
void clearScreen();
void displayTitle();
std::string getString(const std::string& prompt);
int getInteger(const std::string& prompt);
char getCharacter(const std::string& prompt);
std::string getPadding(int elementSize);
int getRandomInteger(int min, int max);

#endif //MINESWEEPER_UTILITY_H
