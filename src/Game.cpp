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

    // initialises game
    grid.setGrid();
    score = 0;
    flags = MINES;
    gameActive = true;

    // game loop
    bool isGameOver = false;
    while (!isGameOver) {
        displayGame();
        playTurn();
        isGameOver = grid.checkDefeat() || grid.checkVictory() || !gameActive;
    }

    // game over
    gameOver();
}

void Game::displayGame() {
    clearScreen();
    displayTitle();
    grid.displayGrid();
    displayInfo();
}

void Game::displayInfo() {
    std::cout << LINE;
    std::cout << getPadding(28 + std::to_string(score).size() + std::to_string(flags).size());
    std::cout << "Score: " << score << "    Flags Remaining: " << flags << '\n';
    std::cout << LINE;
}

std::vector<int> Game::getInput() {

    // initialises input variables
    int row;
    int column;
    char action;
    std::vector<int> userInput;

    // gets and validate user input
    std::cout << '\n';
    bool inputValid = false;
    while (!inputValid) {

        // gets user input
        std::string input = getString("  Enter Action (RCA): ");

        // checks if user quit
        if (input.size() == 1 && toupper(input[0]) == 'Q') {
            userInput.push_back(-1);
            userInput.push_back(-1);
            userInput.push_back('Q');
            return userInput;
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

    // returns validated user input
    userInput.push_back(row);
    userInput.push_back(column);
    userInput.push_back(action);
    return userInput;
}

void Game::playTurn() {

    // gets input
    std::vector<int> userInput = getInput();
    int row = userInput[0];
    int column = userInput[1];
    char action = userInput[2];

    // executes action
    Tile* tile = grid.getTile(row, column);
    if (action == 'R') {
        reveal(tile);
    } else if (action == 'F') {
        flag(tile);
    } else if (action == 'Q') {
        gameActive = false;
    }
}

void Game::reveal(Tile* tile) {
    tile->reveal();
    if (tile->getValue() != -1) {
        score = grid.getScore();
    }
}

void Game::flag(Tile* tile) {
    if (!tile->getIsRevealed()) {
        tile->flag();
        tile->getIsFlagged() ? flags-- : flags++;
        if (flags < 0) {
            tile->flag();
            tile->getIsFlagged() ? flags-- : flags++;
        }
    }
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
