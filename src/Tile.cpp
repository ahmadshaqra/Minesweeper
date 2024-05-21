/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Tile Application File
 **************************************************/

#include "Tile.h"

/**************************************************
    CONSTRUCTORS
 **************************************************/

Tile::Tile() {
    value = 0;
    isFlagged = false;
    isRevealed = false;
}

/**************************************************
    ACCESSOR METHODS
 **************************************************/

int Tile::getValue() {
    return value;
}

bool Tile::getIsRevealed() {
    return isRevealed;
}

bool Tile::getIsFlagged() {
    return isFlagged;
}

std::vector<Tile*> Tile::getAdjacentTiles() {
    return adjacentTiles;
}

/**************************************************
    MUTATOR METHODS
 **************************************************/

void Tile::setValue(int newValue) {
    value = newValue;
}

/**************************************************
    CLASS METHODS
 **************************************************/

char Tile::getSprite() {
    if (!isRevealed) {
        return isFlagged ? FLAGGED : UNREVEALED;
    }
    if (value == -1) {
        return MINE;
    }
    return value == 0 ? REVEALED : char('0' + value);
}

void Tile::flag() {
    if (!isRevealed) {
        isFlagged = !isFlagged;
    }
}

void Tile::reveal() {

    // checks if the tile is flagged or already revealed
    if (isFlagged || isRevealed) {
        return;
    }

    // reveals tile
    isRevealed = true;

    // reveals all adjacent tiles if the current tile value is 0
    if (value == 0) {
        for (Tile* adjacentTile : adjacentTiles) {
            adjacentTile->reveal();
        }
    }
}

void Tile::incrementValue() {
    if (value != -1) {
        value++;
    }
}

void Tile::addAdjacentTile(Tile* tile) {
    adjacentTiles.push_back(tile);
}
