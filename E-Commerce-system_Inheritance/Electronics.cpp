#include "Electronics.h"
#include <windows.h>
#include <iostream>
#include <vector>
// For _getch() function (used to read a single character without echoing to the console)
#include <conio.h>

Electronics::Electronics(int productID, const std::string& name, double price, const std::string& brand, const std::string& model, int screenSize, int energyCapacity) :
    Product(productID, name, price), brand(brand), model(model), screenSize(screenSize), energyCapacity(energyCapacity), smallSize(screenSize) {
    while (smallSize > 10) {
        smallSize /= 10;
    }
    smallSize += 20;
}


void Electronics::display() const {
    display(screenWithText(brand));
}

void Electronics::display(std::vector<std::vector<char>> screen) const {
    std::cout << "Brand: " << brand << "; model: " << model << "; screen size: " << screenSize << "; price: " << price << "; productID: " << productID << ".\n";
    std::cout << "    ";
    for (int i = 0; i < smallSize; i++) { std::cout << "_"; }
    std::cout << std::endl;
    for (int i = 0; i < smallSize / 4; i++) {
        std::cout << "   |";
        for (int j = 0; j < smallSize; j++) { std::cout << screen[i][j]; }
        std::cout << "|\n";
    }
    std::cout << "    ";
    for (int i = 0; i < smallSize; i++) { std::cout << "_"; }
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << std::string(3 - i, ' ') << '/';
        for (int j = 0; j < smallSize + 2 * i; ++j) {
            if (j % 2)
            {
                std::cout << 'L';
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << "\\\n";
    }
    std::cout << " \\";
    for (int i = 0; i < smallSize + 4; i++) { std::cout << "_"; }
    std::cout << "/\n";
}

void Electronics::battery() {
    std::cout << "Battery level: " << batteryLevel << " % (" << batteryLevel * double(energyCapacity) << "mAh).\n";
}


std::vector<std::vector<char>> Electronics::screenWithText(std::string text) const {
    std::vector<std::vector<char>> withText = std::vector<std::vector<char>>(smallSize / 4, std::vector<char>(smallSize, ' '));
    int middle = smallSize / 8; // magic (logically, it should be divided by 2, right?..)
    int textLength = text.length();

    int padding = (smallSize - textLength) / 2;

    for (int i = 0; i < textLength; i++) {
        if (padding + i < smallSize)
            withText[middle][padding + i] = text[i];
    }

    return withText;
}

void Electronics::play() const {
    system("cls");

    int width = smallSize;
    int height = smallSize / 4;
    std::vector<std::vector<char>> screen(height, std::vector<char>(width, '#'));

    {
        int pathLength = height + width;
        int x = 0;
        int y = 0;
        for (int i = 0; i < pathLength - 1; i++) {
            screen[x][y] = ' ';
            if (y >= width - 1 || (rand() % 3 == 0 && x < height - 1)) { x++; }
            else { y++; }
        }
        screen[0][0] = 'X';
        screen[height - 1][width - 1] = '*';
    }

    int playerRow = 0;
    int playerCol = 0;

    display(screen);

    while (true) {
        char userInput = _getch();
        screen[playerRow][playerCol] = ' ';

        if (userInput == 77 && playerCol < width - 1) {  // Right arrow key
            if (screen[playerRow][playerCol] == ' ') {
                ++playerCol;
            }
        }
        else if (userInput == 75 && playerCol > 0) {  // Left arrow key
            if (screen[playerRow][playerCol] == ' ') {
                --playerCol;
            }
        }
        else if (userInput == 72 && playerRow > 0) {  // Up arrow key
            if (screen[playerRow][playerCol] == ' ') {
                --playerRow;
            }
        }
        else if (userInput == 80 && playerRow < height - 1) {  // Down arrow key
            if (screen[playerRow][playerCol] == ' ') {
                ++playerRow;
            }
        }

        screen[playerRow][playerCol] = 'X';
        system("cls");


        if (playerRow == height - 1 && playerCol == width - 1) {
            display(screenWithText("You won!"));
            return;
        }
        else {
            display(screen);
        }
    }
}

