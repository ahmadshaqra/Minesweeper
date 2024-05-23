/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 21/05/2024
    Purpose: Game Application File
 **************************************************/

#include "Game.h"

/**************************************************
    CLASS METHODS
 **************************************************/

void Game::run() {

    // setup grid
    grid.setGrid();

    // game loop
    bool isGameOver = false;
    while (!isGameOver) {
        displayGame();
        isGameOver = playTurn() || grid.checkVictory();
    }

    // game over
    gameOver();
}

void Game::displayGame() {
    clearScreen();
    displayTitle();
    grid.displayGrid();
    std::cout << LINE;
}

bool Game::playTurn() {

    // initialises input variables
    int row;
    int column;
    char action;

    // get and validate user input
    std::cout << '\n';
    bool inputValid = false;
    while (!inputValid) {

        // gets user input
        std::string input = getString("  Enter Action (RCA): ");

        // checks if user quit
        if (input.size() == 1 && toupper(input[0]) == 'Q') {
            return true;
        }

        // validates input size
        if (input.size() != 3) {
            continue;
        }

        // parses input
        row = toupper(input[0]) - 'A';
        column = toupper(input[1]) - 'A';
        action = toupper(input[2]);

        // validates input values
        if (row >= 0 && row < ROWS && column >= 0 && column < COLUMNS && (action == 'R' || action == 'F')) {
            inputValid = true;
        }
    }

    // executes action
    if (action == 'R') {
        return grid.reveal(row, column);
    } else if (action == 'F') {
        grid.flag(row, column);
    }
    return false;
}

void Game::gameOver() {

    // user wins
    if (grid.checkVictory()) {
        displayGame();
        std::cout << "\n  Congratulations! You cleared the grid!\n";

    // user loses
    } else if (grid.checkDefeat()){
        grid.revealGrid();
        displayGame();
        std::cout << "\n  Game over, you hit a mine!\n";

    // user quits
    } else {
        grid.revealGrid();
        displayGame();
        std::cout << "\n  Quitting game . . .\n";
    }

    // wait for user
    wait();
}
