#pragma once
#include <iostream>
#include "Product.h"

class Electronics final : public Product {
    std::string brand;
    std::string model;
    int screenSize;
    int energyCapacity;
    double batteryLevel = 100.0;
public:
    Electronics(int productID, const std::string& name, double price, const std::string& brand, const std::string& model, int screenSize, int energyCapacity);

    void display() const;

    void battery();
};

