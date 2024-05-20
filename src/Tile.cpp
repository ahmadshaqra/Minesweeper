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

/**************************************************
    MUTATOR METHODS
 **************************************************/

void Tile::setValue(int newValue) {
    value = newValue;
}

void Tile::setIsRevealed(bool newState) {
    isRevealed = newState;
}

/**************************************************
    CLASS METHODS
 **************************************************/

char Tile::getSprite() {
    if (isFlagged) {
        return 'F';
    }
    return isRevealed ? '0' + value : '.';
}

void Tile::flag() {
    isFlagged = !isFlagged;
}
