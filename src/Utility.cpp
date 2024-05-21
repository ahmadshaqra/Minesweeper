/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Utility Header File
 **************************************************/

#include "Utility.h"

void wait() {
    std::cout << '\n' << getPadding(31);
    system("pause");
}

void clearScreen() {
    system("cls");
}

void displayTitle() {
    std::cout << LINE << getPadding(TITLE.size()) << TITLE << '\n' << LINE;
}

std::string getString(const std::string& prompt) {
    std::string userInput;
    while (userInput.empty()) {
        std::cout << prompt;
        getline(std::cin, userInput);
    }
    return userInput;
}

int getInteger(const std::string& prompt) {
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

char getCharacter(const std::string& prompt) {
    char userInput = ' ';
    while (!isalpha(userInput)) {
        userInput = getString(prompt)[0];
    }
    return toupper(userInput);
}

std::string getPadding(int elementSize) {
    return std::string(int(floor((LINE.size() - 2 - elementSize) / 2)) + 1, ' ');
}

int getRandomInteger(int min, int max) {
    return rand() % (max - min + 1) + min;
}
