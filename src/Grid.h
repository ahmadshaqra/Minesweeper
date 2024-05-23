/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 21/05/2024
    Purpose: Grid Header File
 **************************************************/

#ifndef MINESWEEPER_GRID_H
#define MINESWEEPER_GRID_H

// including modules
#include <iostream>

// including classes
#include <Constants.h>
#include <Tile.h>
#include <Utility.h>

class Grid {

private:

    // class variables
    Tile* grid[ROWS][COLUMNS];

public:

    // constructors and destructor
    Grid();
    ~Grid() = default;

    // class methods
    void displayGrid();
    void resetGrid();
    void setGrid();
    bool placeMine(int row, int column);
    void revealGrid();
    void addAdjacentTile(int row, int column, int xVector, int yVector);
    bool reveal(int row, int column);
    void flag(int row, int column);
    bool checkVictory();
    bool checkDefeat();
};

#endif //MINESWEEPER_GRID_H
