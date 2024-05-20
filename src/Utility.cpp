/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Utility Header File
 **************************************************/

#include "Utility.h"

/**************************************************
    CLASS METHODS
 **************************************************/

void Utility::wait() {
    std::cout << "\n  ";
    system("pause");
}

void Utility::clearScreen() {
    system("cls");
}

void Utility::displayTitle() {
    std::cout << LINE << TITLE << LINE;
}

std::string Utility::getString(const std::string& prompt) {
    std::string userInput;
    while (userInput.empty()) {
        std::cout << prompt;
        getline(std::cin, userInput);
    }
    return userInput;
}

int Utility::getInteger(const std::string& prompt) {
    std::string userInput;
    bool isNumeric = false;
    while (!isNumeric) {
        userInput = getString(prompt);
        isNumeric = true;
        for (char digit : userInput) {
            if (!isdigit(digit)) {
                isNumeric = false;
            }
        }
    }
    return stoi(userInput);
}

char Utility::getCharacter(const std::string& prompt) {
    char userInput = ' ';
    while (!isalpha(userInput)) {
        userInput = getString(prompt)[0];
    }
    return toupper(userInput);
}
