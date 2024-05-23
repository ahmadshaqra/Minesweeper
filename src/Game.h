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

// including classes
#include <Utility.h>
#include <Grid.h>

class Game {

private:

    // class variables
    Grid grid;

public:

    // class methods
    void run();
    void displayGame();
    bool playTurn();
    void gameOver();
};

#endif //MINESWEEPER_GAME_H
