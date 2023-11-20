#pragma once
#include <iostream>
#include <vector>
#include "Product.h"

class Electronics final : public Product {
    std::string brand;
    std::string model;
    int screenSize = 0;
    int smallSize = 20;
    int energyCapacity;
    double batteryLevel = 100.0;
public:
    Electronics(int productID, const std::string& name, double price, const std::string& brand, const std::string& model, int screenSize, int energyCapacity);

    void display(std::vector<std::vector<char>> screen) const;

    void display() const;

    void play() const;

    void battery();

    std::vector<std::vector<char>> screenWithText(std::string text) const;
};

