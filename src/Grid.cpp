/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 21/05/2024
    Purpose: Grid Application File
 **************************************************/

#include "Grid.h"

/**************************************************
    CONSTRUCTORS
 **************************************************/

Grid::Grid() {

    // initialises all tiles in the grid to null
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            grid[row][column] = nullptr;
        }
    }
}

/**************************************************
    CLASS METHODS
 **************************************************/

void Grid::displayGrid() {

    // display column letters
    std::cout << '\n' << getPadding(COLUMNS * 2);
    for (int column = 0; column < COLUMNS; column++) {
        std::cout << ' ' << char(column + 'A');
    }
    std::cout << '\n';

    // display each row
    for (int row = 0; row < ROWS; row++) {
        std::cout << getPadding(COLUMNS * 2 + 1) << char(row + 'A');
        for (int column = 0; column < COLUMNS; column++) {
            std::cout << ' ';

            // check if tile pointer is null then print out appropriate character
            if (grid[row][column] == nullptr) {
                std::cout << NULL_TILE;
            } else {
                std::cout << grid[row][column]->getSprite();
            }
        }

        // print newline character
        std::cout << '\n';
    }
}

void Grid::resetGrid() {

    // create all the tiles in the grid
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {

            // delete old tile and create new one
            delete grid[row][column];
            grid[row][column] = new Tile();
        }
    }

    // add adjacent tiles to all the tiles in the grid
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            addAdjacentTile(row, column, -1, -1);
            addAdjacentTile(row, column, 0, -1);
            addAdjacentTile(row, column, 1, -1);
            addAdjacentTile(row, column, -1, 0);
            addAdjacentTile(row, column, 1, 0);
            addAdjacentTile(row, column, -1, 1);
            addAdjacentTile(row, column, 0, 1);
            addAdjacentTile(row, column, 1, 1);
        }
    }
}

void Grid::setGrid() {

    // initialises grid
    resetGrid();

    // places mines randomly
    int minesPlaced = 0;
    while (minesPlaced != MINES) {
        int row = getRandomInteger(0, ROWS - 1);
        int column = getRandomInteger(0, COLUMNS - 1);
        if (placeMine(row, column)) {
            minesPlaced++;
        }
    }
}

bool Grid::placeMine(int row, int column) {

    // mine already placed on tile
    if (grid[row][column]->getValue() == -1) {
        return false;
    }

    // place mine on tile
    grid[row][column]->setValue(-1);
    for (Tile* adjacentTile : grid[row][column]->getAdjacentTiles()) {
        adjacentTile->incrementValue();
    }
    return true;
}

void Grid::revealGrid() {

    // iterate over every tile in the grid and reveal its contents
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            grid[row][column]->reveal();
        }
    }
}

void Grid::addAdjacentTile(int row, int column, int xVector, int yVector) {

    // checks if the adjacent tile exists before adding it to the current tile's adjacent tile list
    if (row + xVector >= 0 && row + xVector < ROWS && column + yVector >= 0 && column + yVector < COLUMNS) {
        grid[row][column]->addAdjacentTile(grid[row + xVector][column + yVector]);
    }
}

bool Grid::reveal(int row, int column) {
    if (grid[row][column]->getIsFlagged()) {
        return false;
    }
    grid[row][column]->reveal();
    if (grid[row][column]->getValue() == -1) {
        return true;
    }
    return false;
}

void Grid::flag(int row, int column) {
    grid[row][column]->flag();
}

bool Grid::checkVictory() {

    // checks if there are any unrevealed tiles that do not contain a mine
    bool victory = true;
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            if (!grid[row][column]->getIsRevealed() && grid[row][column]->getValue() != -1) {
                victory = false;
            }
        }
    }
    return victory;
}
