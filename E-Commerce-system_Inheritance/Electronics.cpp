#include "Electronics.h"
#include <windows.h>

Electronics::Electronics(int productID, const std::string& name, double price, const std::string& brand, const std::string& model, int screenSize, int energyCapacity) :
    Product(productID, name, price), brand(brand), model(model), screenSize(screenSize), energyCapacity(energyCapacity), smallSize(screenSize) {
    while (smallSize > 10) {
        smallSize /= 10;
    }
    smallSize += 20;
}


void Electronics::display() const {
    std::cout << "Brand: " << brand << "; model: " << model << "; screen size: " << screenSize << "; price: " << price << "; productID: " << productID << ".\n";
    std::cout << "    ";
    std::vector<std::vector<char>> emptyScreen = this->emptyScreen();
    for (int i = 0; i < smallSize; i++) { std::cout << "_"; }
    std::cout << std::endl;
    for (int i = 0; i < smallSize / 4; i++) {
        std::cout << "   |";
        for (int j = 0; j < smallSize; j++) { std::cout << emptyScreen[i][j]; }
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

void Electronics::play() const {
    system("cls");
    display();
}

std::vector<std::vector<char>> Electronics::emptyScreen() const {
    return std::vector<std::vector<char>>(smallSize / 4, std::vector<char>(smallSize, ' '));
}

std::vector<std::vector<char>> Electronics::screenWithText() const {
    std::vector<std::vector<char>> withText = std::vector<std::vector<char>>(smallSize / 4, std::vector<char>(smallSize, ' '));
    int middle = smallSize / 2;
    int brandLineLength = brand.length();
    int padding = (smallSize - brandLineLength) / 2;
    for (int i = 0; i < brandLineLength; i++)
    {
        withText[middle][padding + i] = brand[i];
    }
    return withText;
}

