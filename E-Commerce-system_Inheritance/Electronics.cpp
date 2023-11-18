#include "Electronics.h"

Electronics::Electronics(int productID, const std::string& name, double price, const std::string& brand, const std::string& model, int screenSize, int energyCapacity) :
    Product(productID, name, price), brand(brand), model(model), screenSize(screenSize), energyCapacity(energyCapacity) {}

void Electronics::display() const {
    int smallSize = screenSize;
    while (smallSize > 60)
    {
        smallSize /= 10;
    }
    std::cout << "Brand: " << brand << "; model: " << model << "; screen size: " << screenSize << "; price: " << price << "; productID: " << productID << ".\n";
    std::cout << "    ";
    for (int i = 0; i < smallSize; i++) { std::cout << "_"; }
    std::cout << std::endl;
    for (int i = 0; i < smallSize / 5; i++) {
        std::cout << "   |";
        for (int j = 0; j < smallSize; j++) { std::cout << " "; }
        std::cout << "|\n";
    }
    std::cout << "    ";
    for (int i = 0; i < smallSize; i++) { std::cout << "_"; }
    std::cout << std::endl;
    std::cout << "  /";
    for (int i = 0; i < smallSize + 2; i++) { std::cout << "="; }
    std::cout << "\\\n";
    std::cout << " /";
    for (int i = 0; i < smallSize + 4; i++) { std::cout << "="; }
    std::cout << "\\\n";
    std::cout << "/";
    for (int i = 0; i < smallSize + 6; i++) { std::cout << "="; }
    std::cout << "\\\n";
    std::cout << "\\";
    for (int i = 0; i < smallSize + 6; i++) { std::cout << "_"; }
    std::cout << "/\n";
}

void Electronics::battery() {
    std::cout << "Battery level: " << batteryLevel << " % (" << batteryLevel * double(energyCapacity) << "mAh).\n";
}
