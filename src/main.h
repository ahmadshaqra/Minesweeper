/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Main Header File
 **************************************************/

#ifndef MINESWEEPER_MAIN_H
#define MINESWEEPER_MAIN_H

// including modules
#include <iostream>
#include <string>

// declaring constants
const std::string LINE = " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
const std::string TITLE = "                    Minesweeper                    \n";

// declaring helper functions
void wait();
void clearScreen();
void displayTitle();
std::string getString(std::string prompt);
int getInteger(std::string prompt, int min, int max);
char getCharacter(std::string prompt);

#endif //MINESWEEPER_MAIN_H
