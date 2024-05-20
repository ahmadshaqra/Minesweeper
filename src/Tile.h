/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Tile Header File
 **************************************************/

#ifndef MINESWEEPER_TILE_H
#define MINESWEEPER_TILE_H

class Tile {

private:

    // class variables
    int value;
    bool isRevealed;
    bool isFlagged;

public:

    // constructors and destructor
    Tile();
    ~Tile() = default;

    // accessor methods
    int getValue();
    bool getIsRevealed();

    // mutator methods
    void setValue(int newValue);
    void setIsRevealed(bool newState);

    // class methods
    char getSprite();
    void flag();
};

#endif //MINESWEEPER_TILE_H
