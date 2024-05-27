/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Constants Header File
 **************************************************/

#ifndef MINESWEEPER_CONSTANTS_H
#define MINESWEEPER_CONSTANTS_H

// including modules
#include <string>

// declaring constants
const std::string LINE = " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
const std::string TITLE = "Minesweeper";
const int ROWS = 10;
const int COLUMNS = 10;
const int MINES = 7;
const char UNREVEALED = '#';
const char REVEALED = '.';
const char FLAGGED = '~';
const char MINE = '@';
const char NULL_TILE = '?';
const int TILE_POINTS = 10;

#endif //MINESWEEPER_CONSTANTS_H
