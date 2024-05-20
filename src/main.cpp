/**************************************************
    Project: Minesweeper
    Author: Ahmad Abu-Shaqra
    Date: 20/05/2024
    Purpose: Main Application File
 **************************************************/

#include "main.h"

int main() {
    displayTitle();
    std::string name = getString("  Enter name: ");
    int age = getInteger("  Enter age: ", 0, 100);
    char initial = getCharacter("  Enter initial of last name: ");
    std::cout << "  Your name: " << name << std::endl;
    std::cout << "  Your age: " << age << std::endl;
    std::cout << "  Your last name initial: " << initial << std::endl;
    wait();
    clearScreen();
    displayTitle();
    std::cout << "  Hello world!\n";
    wait();
    return 0;
}

/**************************************************
    HELPER FUNCTIONS
 **************************************************/

void wait() {
    std::cout << "\n    ";
    system("pause");
}

void clearScreen() {
    system("cls");
}

void displayTitle() {
    std::cout << LINE << TITLE << LINE;
}

std::string getString(std::string prompt) {
    // gets a line response (spaces included)
    std::string userInput = "";
    while (userInput == "") {
        std::cout << prompt;
        getline(std::cin, userInput);
    }
    return userInput;
}

int getInteger(std::string prompt, int min, int max) {
    // ask for a numeric response from the user
    int number = min - 1;
    while (number < min || number > max) {
        std::string userInput = getString(prompt);
        bool isNumeric = true;
        for (char digit : userInput) {
            if (!isdigit(digit)) {
                isNumeric = false;
            }
        }
        if (isNumeric) {
            number = stoi(userInput);
        }
    }
    return number;
}

char getCharacter(std::string prompt) {
    // ask a single letter response question
    char userInput = ' ';
    while (!isalpha(userInput)) {
        userInput = getString(prompt)[0];
    }
    return toupper(userInput);
}
