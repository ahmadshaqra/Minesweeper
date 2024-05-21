/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Main Application File
 **************************************************/

#include "main.h"

int main() {

    // seeding randoms
    srand(unsigned(time(nullptr)));

    // placeholder code
    displayTitle();
    grid = Grid();
    grid.setGrid();
    grid.displayGrid();
    wait();

    clearScreen();
    displayTitle();
    grid.revealGrid();
    grid.displayGrid();
    wait();

    // exit
    return 0;
}
