/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 21/05/2024
    Purpose: Game Header File
 **************************************************/

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

// including modules
#include <iostream>
#include <string>
#include <vector>

// including classes
#include <Utility.h>
#include <Grid.h>

class Game {

private:

    // class variables
    Grid grid;
    int score;
    int flags;
    bool gameActive;

public:

    // class methods
    void run();
    void displayGame();
    void displayInfo();
    std::vector<int> getInput();
    void playTurn();
    void reveal(Tile* tile);
    void flag(Tile* tile);
    void gameOver();
};

#endif //MINESWEEPER_GAME_H
