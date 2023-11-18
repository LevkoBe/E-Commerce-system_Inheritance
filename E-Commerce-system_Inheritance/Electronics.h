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
    Electronics(int productID, const std::string& name, double price, const std::string& brand, const std::string& model, int screenSize, int energyCapacity) :
        Product(productID, name, price), brand(brand), model(model), screenSize(screenSize), energyCapacity(energyCapacity) {};
    void display() const override {
        std::cout << "Brand: " << brand << "; model: " << model << "; screen size: " << screenSize << "; price: " << price << "; productID: " << productID << ".\n";
    }
    void battery() {
        std::cout << "Battery level : " << batteryLevel << " % (" << batteryLevel * double(energyCapacity) << "mAh).\n";
    }
};

