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

    // running game
    game.run();

    // exiting
    return 0;
}
