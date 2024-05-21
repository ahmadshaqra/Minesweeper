/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Tile Header File
 **************************************************/

#ifndef MINESWEEPER_TILE_H
#define MINESWEEPER_TILE_H

// including modules
#include <vector>

// including classes
#include <Constants.h>

class Tile {

private:

    // class variables
    int value;
    bool isRevealed;
    bool isFlagged;
    std::vector<Tile*> adjacentTiles;

public:

    // constructors and destructor
    Tile();
    ~Tile() = default;

    // accessor methods
    int getValue();
    bool getIsRevealed();
    bool getIsFlagged();
    std::vector<Tile*> getAdjacentTiles();

    // mutator methods
    void setValue(int newValue);

    // class methods
    char getSprite();
    void flag();
    void reveal();
    void incrementValue();
    void addAdjacentTile(Tile* tile);
};

#endif //MINESWEEPER_TILE_H
